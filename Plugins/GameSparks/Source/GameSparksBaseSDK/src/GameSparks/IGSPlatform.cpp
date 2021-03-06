#if defined(WINAPI_FAMILY)
#define __STDC_WANT_SECURE_LIB__ 0
#define sprintf_s(buf, size, fmt, ...) sprintf(buf, fmt, __VA_ARGS__)
#define swprintf_s(buf, size, fmt, ...) swprintf(buf, size, fmt, __VA_ARGS__)
#endif

#include <GameSparks/IGSPlatform.h>

#include <fstream>

#if GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
#	include <sys/types.h>
#	include <unistd.h>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32 || GS_TARGET_PLATFORM == GS_PLATFORM_XBOXONE
#if WINAPI_FAMILY_DESKTOP_APP == WINAPI_FAMILY
#	include <locale>
#	include <shlwapi.h>
#	include <shlobj.h>
#	pragma comment(lib,"shlwapi.lib")
//#	define GS_WINDOWS_DESKTOP
#else
#	include <Objbase.h>
//#	include <wrl.h>
#	undef nullptr
#	include <wrl.h>
#	include <windows.storage.h>
#	include <codecvt>
#	define GS_WINDOWS_APP
extern "C" int _getch(void) { return 0; }

#endif
#	pragma comment(lib, "Rpcrt4.lib")
#	include <Rpc.h>
#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC || GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
#   ifdef __APPLE__
#       include "TargetConditionals.h"
        gsstl::string get_osx_device_id();
#   endif
#   if defined(__linux__)
#      include <linux/limits.h>
#      include <string.h>
#   endif
#   include <sys/stat.h> // for mkdir

	/* works like mkdir(1) used as "mkdir -p" */
	static void mkdirp(const char *dir) {
	    char tmp[PATH_MAX];
	    char *p = NULL;
	    size_t len;
	    
	    snprintf(tmp, sizeof(tmp),"%s",dir);
	    len = strlen(tmp);
	    if(tmp[len - 1] == '/')
	        tmp[len - 1] = 0;
	    for(p = tmp + 1; *p; p++)
	        if(*p == '/') {
	            *p = 0;
	            mkdir(tmp, S_IRWXU | S_IRWXG);
	            *p = '/';
	        }
	    mkdir(tmp, S_IRWXU | S_IRWXG);
	}

#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    gsstl::string gs_ios_get_writeable_base_path();
    gsstl::string get_ios_device_id();
#elif defined(__ORBIS__)
#	include <save_data.h>
#	include <cassert>
#	include <stdlib.h>
#else
//#	include <uuid/uuid.h>
#endif

#if GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
#	include <s3e.h>
#endif

gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats();


namespace GameSparks { namespace Core {


// trim from start
static inline gsstl::string &ltrim(gsstl::string &s) {
        s.erase(s.begin(), gsstl::find_if(s.begin(), s.end(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))));
        return s;
}

// trim from end
static inline gsstl::string &rtrim(gsstl::string &s) {
        s.erase(gsstl::find_if(s.rbegin(), s.rend(), gsstl::not1(gsstl::ptr_fun<int, int>(isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline gsstl::string &trim(gsstl::string &s) {
        return ltrim(rtrim(s));
}

#if GS_TARGET_PLATFORM != GS_PLATFORM_MAC && GS_TARGET_PLATFORM != GS_PLATFORM_IOS
static gsstl::string generate_guid()
{
	gsstl::string ret = "NO-UUID-SUPPORT-FOR-THIS-PLATFORM";

	#ifdef WIN32
		#if defined(GS_WINDOWS_DESKTOP)
			UUID uuid;
			UuidCreate(&uuid);

			unsigned char * str;
			UuidToStringA(&uuid, &str);

			ret = gsstl::string((char*)str);

			RpcStringFreeA(&str);
		#else
			GUID guid;
			if (S_OK != CoCreateGuid(&guid))
				return "GUID-CREATION-FAILED";

			OLECHAR* bstrGuid;
			StringFromCLSID(guid, &bstrGuid);

			typedef std::codecvt_utf8<wchar_t> convert_type;
			std::wstring_convert<convert_type, wchar_t> converter;

			ret = converter.to_bytes(bstrGuid);

			// ensure memory is freed
			::CoTaskMemFree(bstrGuid);
		#endif
	#elif defined(ANDROID) || defined(__linux__)
		gsstl::ifstream ifs("/proc/sys/kernel/random/uuid");
		ifs >> ret;
	#elif defined(__ORBIS__)
		SceKernelUuid uuid;
		int result = sceKernelUuidCreate(&uuid);
		assert(result == 0);

		char hex[sizeof(uuid)*2+1];
		snprintf(hex, sizeof(hex), "%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x"
			, (int)uuid.timeLow
			, (int)uuid.timeMid
			, (int)uuid.timeHiAndVersion
			, (int)uuid.clockSeqHiAndReserved
			, (int)uuid.clockSeqLow
			, (int)uuid.node[0]
			, (int)uuid.node[1]
			, (int)uuid.node[2]
			, (int)uuid.node[3]
			, (int)uuid.node[4]
			, (int)uuid.node[5]

		);
		ret = hex;

	#endif
	/*#else
		uuid_t uuid;
		uuid_generate_random(uuid);
		char s[37];
		uuid_unparse(uuid, s);
		ret = s;
	#endif
		return ret;
	*/
	//assert(false);
	return trim(ret);
}
#endif


gsstl::string IGSPlatform::GetDeviceId() const
{
	static gsstl::string device_id;

	if (device_id.empty())
	{
		#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
			device_id = get_osx_device_id();
		#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
			device_id = get_ios_device_id();
		#elif GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
			device_id = s3eDeviceGetString(S3E_DEVICE_UNIQUE_ID);
		#else
			device_id = LoadValue("device_id");
			if (device_id.empty())
			{
				device_id = generate_guid();
				StoreValue("device_id", device_id);
			}
		#endif

		device_id = trim(device_id);
	}

	return device_id;
}



gsstl::string IGSPlatform::GetDeviceOS() const
{
	#if GS_TARGET_PLATFORM == GS_PLATFORM_MAC
		return "OSX";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
		return "IOS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID
		return "Android";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
		return "Linux";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE
		return "Marmelade";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BADA
		return "Bada";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_BLACKBERRY
		return "Blackberry";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_NACL
		return "NaCl";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_EMSCRIPTEN
		return "emscripten";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_TIZEN
		return "Tizen";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_QT5
		return "QTS";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WINRT
		return "W8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WP8
		return "WP8";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_PS4
		return "PS4";
	#elif GS_TARGET_PLATFORM == GS_PLATFORM_XBOXONE
		return "XBOXONE";
	#else
	#   error "Unsupported platform"
		return "Unknown";
	#endif
}


gsstl::string IGSPlatform::GetPlatform() const
{
	return GetDeviceOS();
}

#if defined(WIN32)
// convert UTF-8 string to wstring
static std::wstring utf8_to_wstring(const std::string& str)
{
	int output_size = MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), static_cast<int>(str.size()), NULL, 0);
	assert(output_size > 0);
	gsstl::vector<wchar_t> buffer(output_size);
	int result = MultiByteToWideChar(CP_UTF8, NULL, str.c_str(), static_cast<int>(str.size()), buffer.data(), static_cast<int>(buffer.size()));
	(void)result; // unused in release builds
	assert( result == output_size );
	std::wstring ret(buffer.begin(), buffer.end());
	return ret;
	//std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	//return myconv.from_bytes(str);
}

// convert wstring to UTF-8 string
static std::string wstring_to_utf8(const std::wstring& str)
{
	int output_size = WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), static_cast<int>(str.size()), NULL, 0, NULL, NULL);
	assert(output_size > 0);
	gsstl::vector<char> buffer(output_size);
	int result = WideCharToMultiByte(CP_UTF8, NULL, str.c_str(), static_cast<int>(str.size()), buffer.data(), static_cast<int>(buffer.size()), NULL, NULL);
	(void)result; // unused in release builds
	assert(result == output_size);
	std::string ret(buffer.begin(), buffer.end());
	return ret;

	//std::wstring_convert<std::codecvt_utf8<wchar_t>> myconv;
	//return myconv.to_bytes(str);
}
#endif

// variant of fopen that takes care of the fact, that we cannot use utf-8 for paths on windows
static FILE* gs_fopen(const gsstl::string& path, const char* mode)
{
#if defined(WIN32)
	return _wfopen(utf8_to_wstring(path).c_str(), utf8_to_wstring(mode).c_str());
#else
	return fopen(path.c_str(), mode);
#endif /* WIN32 */
}


void IGSPlatform::StoreValue(const gsstl::string& key, const gsstl::string& value) const
{
	// TODO: port to all the platforms
	FILE* f = gs_fopen(ToWritableLocation(key), "wb");
	assert(f);
	if (!f)
	{
    	DebugMsg("**** Failed to store value to '" + key + "'");
    	return;
	}
	size_t written = fwrite(value.c_str(), 1, value.size(), f);
    (void)(written);
    assert(written == value.size());
	fclose(f);
}


gsstl::string IGSPlatform::LoadValue(const gsstl::string& key) const
{
	// TODO: port to all the platforms
	FILE *f = gs_fopen(ToWritableLocation(key), "rb");
	
    if(!f)
    {
    	//DebugMsg("**** Failed to load value from '" + ToWritableLocation(key) + "'");
        return "";
    }
    
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	if (fsize <= 0)
	{
		fclose(f);
		return "";
	}
	fseek(f, 0, SEEK_SET);
    gsstl::vector<char> bytes(static_cast<gsstl::vector<char>::size_type>(fsize));
	size_t read_bytes = fread(&bytes.front(), 1, fsize, f);
    (void)(read_bytes);
	assert(read_bytes == static_cast<size_t>(fsize));
	fclose(f);
	return gsstl::string( bytes.begin(), bytes.end() );
}



gsstl::string IGSPlatform::ToWritableLocation(gsstl::string desired_name) const
{
	desired_name = "gamesparks_" + desired_name;

	#if GS_TARGET_PLATFORM == GS_PLATFORM_MARMALADE || defined(GS_OVERRIDE_TOWRITABLELOCATION) // marmalade || windows; Note, that windows is for testing only. You should not put the files into the working directoy
    // http://docs.madewithmarmalade.com/display/MD/S3E+File+overview
	// This should work on marmalade
	return desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_WIN32 || GS_TARGET_PLATFORM == GS_PLATFORM_XBOXONE
		#if defined(GS_WINDOWS_DESKTOP)
			static gsstl::string base_path;

			if (base_path.empty())
			{
				wchar_t szPath[MAX_PATH];
				if (SUCCEEDED(SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, szPath)))
				{
					base_path = wstring_to_utf8(szPath);
				}
				else
				{
					DebugMsg("Failed to get CSIDL_APPDATA path.");
					base_path = "./";
					assert(false);
				}

				base_path = base_path + "\\GameSparks\\" + m_apiKey + "\\";

				std::replace(base_path.begin(), base_path.end(), '/', '\\');

				int result = SHCreateDirectoryExW(NULL, utf8_to_wstring(base_path).c_str(), NULL);

				if (
					result != ERROR_SUCCESS &&
					result != ERROR_FILE_EXISTS &&
					result != ERROR_ALREADY_EXISTS
					)
				{
					DebugMsg("Failed to create directory.");
					// if you end up here, you probably forgot to set-up your credentials.
					// The default credentials in the sample contain characters that are not valid in windows paths ('<' and '>')
					assert(false);
				}
			}

			assert(!base_path.empty());

			return base_path + desired_name;
		#else
			// you might need to ensure, that you allocated storage via your manifest
			static std::wstring wbase_path = Windows::Storage::ApplicationData::Current->LocalFolder->Path->Data();
			static auto base_path = wstring_to_utf8(wbase_path);
			return base_path + "\\" + desired_name;
		#endif /* defined(GS_WINDOWS_DESKTOP) */

        #elif GS_TARGET_PLATFORM == GS_PLATFORM_LINUX
        static gsstl::string base_path;
        if (base_path.empty())
        {
            // the environment might not be correctly setup, then we store data in /tmp
            gsstl::string writable_path("/tmp/GameSparks");
            
            if(char* homedir = getenv("HOME"))
                writable_path = homedir;
                
             writable_path += "/.gamesparks/" + m_apiKey + "/";
             
             struct stat s;
             
             if (0 != stat(writable_path.c_str(), &s) ) // Check if directory exists
             {
                 mkdirp(writable_path.c_str());
             }
             
             base_path = writable_path;
        }
        
        return base_path + desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_MAC

    ////////////////// OS X
    static gsstl::string base_path;
    if (base_path.empty())
    {
		// the environment might not be correctly setup, then we store data in /tmp
        gsstl::string writable_path("/tmp/GameSparks");

		if(char* homedir = getenv("HOME"))
			writable_path = homedir;

		writable_path += "/Library/Application Support/GameSparks/" + m_apiKey + "/";
        
        struct stat s;// = {0};
        
        if (0 != stat(writable_path.c_str(), &s) ) // Check if directory exists
        {
            mkdirp(writable_path.c_str());
        }
    
        base_path = writable_path;
    }
    
    return base_path + desired_name;

	#elif GS_TARGET_PLATFORM == GS_PLATFORM_ANDROID

	//////////////////////////////// Android
	// http://stackoverflow.com/questions/6276933/getfilesdir-from-ndk
	static gsstl::string base_path = "";
	if (base_path.empty())
	{
		char buf[200]; // 64bit int can be 20 digits at most
		sprintf(buf, "/proc/%i/cmdline", (int)getpid());

		FILE* f = fopen(buf, "rb");
		if (!f)
		{
			DebugMsg("Failed to get writable path");
			return "./" + desired_name;
		}

		fread(buf, 1, sizeof(buf), f);
		fclose(f);

		if(buf[0] == '.') // if executed via adb shell
			return "./" + desired_name;

		// bytes not contains the list of null separated command line arguments, the string constructor below will copy until the first null byte
		base_path = "/data/data/" + gsstl::string(buf) + "/";
	}
	return base_path + desired_name;

    #elif GS_TARGET_PLATFORM == GS_PLATFORM_IOS
    static gsstl::string base_path = gs_ios_get_writeable_base_path();
    return base_path + "/" + desired_name;

	#elif defined(__ORBIS__)
	return "/data/" + desired_name;
	#else
    #   error "ToWritableLocation not implemented for this platform. If you're planing on overriding it yourself, please define GS_OVERRIDE_TOWRITABLELOCATION"
	#endif
}

static bool gs_is_digits(const std::string &str)
{
    return str.find_first_not_of("0123456789") == std::string::npos;
}

// split s by '.' and return at most the first two parts. if non digits are found in the first two places, an empty vector is returned.
// if only one part is found, an empty vector is returned
static gsstl::vector<gsstl::string> gs_major_minor_version_split(const gsstl::string& s)
{
    const char delim = '.';
    gsstl::vector<gsstl::string> tokens;
    size_t start = 0U;
    size_t end = s.find(delim);
    for (;end != std::string::npos;start = end + 1, end = s.find(delim, start))
    {
        gsstl::string part = s.substr(start, end - start);
        if (!gs_is_digits(part))
        {
            return gsstl::vector<gsstl::string>();
        }
        if(!part.empty())
        {
            tokens.push_back(part);
        }
        if(tokens.size() == 2)
        {
            return tokens;
        }
    }

    gsstl::string part = s.substr(start, end);
    if(!part.empty())
    {
        tokens.push_back(part);
    }
    if(tokens.size() != 2)
    {
        return gsstl::vector<gsstl::string>();
    }
    return tokens;
}

gsstl::map<gsstl::string, gsstl::string> IGSPlatform::GetDeviceStats() const
{
	gsstl::map<gsstl::string, gsstl::string> stats = gs_get_device_stats();

	// synthesize os.version.major and os.version.major.minor
    if( stats.count("os.version") > 0 )
    {
        const gsstl::string& version = stats["os.version"];
        gsstl::vector<gsstl::string> major_minor = gs_major_minor_version_split(version);
        if(major_minor.size() == 2)
        {
            stats["os.version.major"] = major_minor[0];
            stats["os.version.major.minor"] = major_minor[0] + "." + major_minor[1];
        }
    }

    return stats;
}



	}} // namespace GameSparks { namespace Core {


#include <sstream>

namespace
{
	template <typename T>
	static gsstl::string to_string(const T& o)
	{
		std::stringstream ss;
		ss << std::boolalpha << o;
		return ss.str();
	}
}





#if defined(__linux__)
#   include <sys/sysinfo.h>
#	include <thread>

namespace
{
	std::string get_mem_info()
	{
		#if (defined(__ANDROID_API__) && (__ANDROID_API__ >= 9)) || defined(__linux__)
		struct sysinfo sysi;

		if (sysinfo (&sysi) == 0)
		{
			return to_string(sysi.totalram * sysi.mem_unit / (1024)) + " kB";
		}
		#endif

		std::ifstream ifs("/proc/meminfo");
		if(ifs.good())
		{
			std::string key, value, unit;
			ifs >> key;
			ifs >> value;
			ifs >> unit;

			if(key == "MemTotal:")
			{
				return value + " " + unit;
			}
		}

		return "";
	}


	// trim from start
	static inline std::string &ltrim(std::string &s) {
		s.erase(s.begin(), std::find_if(s.begin(), s.end(),
										std::not1(std::ptr_fun<int, int>(std::isspace))));
		return s;
	}

	// trim from end
	static inline std::string &rtrim(std::string &s) {
		s.erase(std::find_if(s.rbegin(), s.rend(),
							 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
		return s;
	}

	// trim from both ends
	static inline std::string &trim(std::string &s) {
		return ltrim(rtrim(s));
	}

	static std::string get_cpu_model()
	{
		/*
         * Format:
         * processor	: 1
         * empty lines allowed
         * lax parser, fault tolerant
         * */

		std::ifstream ifs("/proc/cpuinfo");

		std::string line;
		while(std::getline(ifs, line))
		{
			std::istringstream iss(line);

			std::string key, value;

			if(std::getline(iss, key, ':') && std::getline(iss, value, '\0'))
			{
				trim(key);
				trim(value);
				if(key == "Hardware" || key == "model name")
					return value;
			}
		}
		return "";
	}
}
#endif


#if defined(__linux__) && defined(__ANDROID__)
#   include <unistd.h>
#   include <sys/ioctl.h>
#   include <linux/fb.h>
#   include <sys/stat.h>
#   include <fcntl.h>

namespace {

    // __system_property_get is a private API and was removed from the arm64 libc.a - so we parse it our selves
    static std::string get_system_property(const std::string& name)
    {
        static std::map<std::string, std::string> system_properties;
        if(system_properties.empty())
        {
            /*
             * Format:
             *   key=value
             *   comments start with '#'
             *   empty lines allowed
             *   lax parser, fault tolerant
             * */

            std::ifstream ifs("/system/build.prop");
            //std::istringstream ifs(prop_test_string);

            std::string line;
            while(std::getline(ifs, line))
            {
                if( line.size() == 0 || line[0] == '#' )
                    continue;

                std::istringstream iss(line);
                std::string key, value;
                if(std::getline(iss, key, '=') && std::getline(iss, value, '\0'))
                {
                    system_properties[key] = value;
                }
            }
        }
        return system_properties[name];
    }


	// this will most likely fail
	static std::string get_display_resolution()
	{
		// http://stackoverflow.com/questions/14377407/android-how-to-get-display-resolution-in-native-code
		std::string res_string = "";

		struct fb_var_screeninfo fb_var;
		int fd = open("/dev/graphics/fb0", O_RDONLY);
		if(fd > 0)
		{
			if(0 == ioctl(fd, FBIOGET_VSCREENINFO, &fb_var))
			{
				res_string = to_string(fb_var.width) + "x" + to_string(fb_var.height);
			}
			close(fd);
		}

		return res_string;
	}
}



gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats()
{
	gsstl::map<gsstl::string, gsstl::string> ret;

    ret["os.name"]      = "Android";
    ret["memory"]       = get_mem_info();
    auto resolution = get_display_resolution();
    if(!resolution.empty())
    {
        ret["resolution"]   = get_display_resolution();
    }
	ret["model"]        = get_system_property("ro.product.model");
	ret["cpu.vendor"]   = get_cpu_model();
	ret["cpu.cores"]    = to_string(std::thread::hardware_concurrency());
	ret["os.version"]   = get_system_property("ro.build.version.sdk");
	ret["manufacturer"] = get_system_property("ro.product.manufacturer");

	return ret;
}
#endif


#if defined(__linux__) && !defined(__ANDROID__)
#include <sys/utsname.h>

gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats()
{
	gsstl::map<gsstl::string, gsstl::string> ret;

    utsname info;
    if(0 == uname(&info))
    {
        ret["os.name"]      = info.sysname;
    	ret["os.version"]   = info.release;
    }
    else
    {
        ret["os.name"]      = "Linux";
    }

    ret["memory"]       = get_mem_info();
	ret["cpu.vendor"]   = get_cpu_model();
	ret["cpu.cores"]    = to_string(std::thread::hardware_concurrency());

    //ret["manufacturer"] = "Linux";
	//ret["model"]        = "Linux";
    //ret["resolution"]   = get_display_resolution();

	return ret;
}

#endif


#if defined(WIN32)
#    if WINAPI_FAMILY_DESKTOP_APP == WINAPI_FAMILY
#        include <shlwapi.h>
#        include <shlobj.h>
#        include <cassert>
#        include <iostream>
#        pragma comment(lib, "shlwapi.lib")
#        pragma comment(lib, "Rpcrt4.lib")
#        pragma comment(lib, "Version.lib")
#    else
#        include <Objbase.h>
#        include <wrl.h>
#        include <windows.storage.h>
#    endif


#if WINAPI_FAMILY_DESKTOP_APP == WINAPI_FAMILY
#include <thread>
#include <intrin.h>

namespace
{
	static std::string get_pe_version(const std::wstring& executable)
	{
		DWORD version_buf_len, handle;
		if ((version_buf_len = GetFileVersionInfoSizeW(executable.c_str(), &handle)) == 0)
		{
			auto eid = GetLastError();
			std::cerr << "GetFileVersionInfoSize failed: " << eid << '\n';
			return{};
		}

		// pre-allocated buffer for version information to be stored
		std::vector<BYTE> version_buf(version_buf_len);
		if (!GetFileVersionInfoW(executable.c_str(), 0, version_buf_len, version_buf.data()))
		{
			auto eid = GetLastError();
			std::cerr << "GetFileVersionInfo failed: " << eid << '\n';
			return {};
		}

		VS_FIXEDFILEINFO *p_verinfo = NULL; // pointer to location within version_buf
		UINT len = 0;

		// query version value
		if (!VerQueryValueA(version_buf.data(), "\\", reinterpret_cast<LPVOID *>(&p_verinfo), &len))
		{
			auto eid = GetLastError();
			std::cerr << "VerQueryValue failed: " << eid << '\n';
			return{};
		}

		std::stringstream s;
		if (p_verinfo->dwSignature == 0XFEEF04BD)
		{
			s << HIWORD(p_verinfo->dwProductVersionMS) << "."
			  << LOWORD(p_verinfo->dwProductVersionMS) << "."
			  << HIWORD(p_verinfo->dwProductVersionLS) << "."
			  << LOWORD(p_verinfo->dwProductVersionLS);
		}
		return s.str();
	}

	static std::string get_mem_info()
	{
		MEMORYSTATUSEX memoryStatus;
		memoryStatus.dwLength = sizeof(memoryStatus);
		if (GlobalMemoryStatusEx(&memoryStatus))
		{
			return to_string(memoryStatus.ullTotalPhys / 1024 / 1024) + " MB";
		}
		else
		{
			return "";
		}
	}

	static std::string get_cpu_model()
	{
		int cpuInfo[4] = { -1 };
		char CPUBrandString[0x40];

		memset(CPUBrandString, 0, sizeof(CPUBrandString));

		__cpuid(cpuInfo, 0x80000002);
		memcpy(CPUBrandString, cpuInfo, sizeof(cpuInfo));

		__cpuid(cpuInfo, 0x80000003);
		memcpy(CPUBrandString + 16, cpuInfo, sizeof(cpuInfo));

		__cpuid(cpuInfo, 0x80000004);
		memcpy(CPUBrandString + 32, cpuInfo, sizeof(cpuInfo));

		return CPUBrandString;
	}

	static std::string get_display_resolution()
	{
		RECT desktop;
		const HWND hDesktop = GetDesktopWindow();
		GetWindowRect(hDesktop, &desktop);
		auto width = desktop.right - desktop.left;
		auto height = desktop.bottom - desktop.top;
		return to_string(width) + "x" + to_string(height);
	}
}


gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats()
{
	gsstl::map<gsstl::string, gsstl::string> ret;

	ret["os.name"] = "Windows";
	ret["os.version"] = get_pe_version(L"kernel32");
	ret["manufacturer"] = "Microsoft";
	ret["model"]        = "PC";

	ret["memory"] = get_mem_info();
	ret["cpu.vendor"] = get_cpu_model();
	ret["cpu.cores"] = to_string(std::thread::hardware_concurrency());

	ret["resolution"]   = get_display_resolution();

	return ret;
}

#elif !defined(_DURANGO) // WinRT, etc.

namespace
{
	static std::string get_cpu_model()
	{
		SYSTEM_INFO systemInfo;
		GetNativeSystemInfo(&systemInfo);
		switch (systemInfo.wProcessorArchitecture)
		{
			case PROCESSOR_ARCHITECTURE_ARM: return "ARM";
			case PROCESSOR_ARCHITECTURE_AMD64: return "AMD64";
			case PROCESSOR_ARCHITECTURE_IA64: return "IA64";
			case PROCESSOR_ARCHITECTURE_INTEL: return "INTEL";
			default: return "";
		}
	}

	
}

#include <windows.security.exchangeactivesyncprovisioning.h>

gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats()
{
	gsstl::map<gsstl::string, gsstl::string> ret;

	// who would have guessed ?
	auto deviceInfo = ref new Windows::Security::ExchangeActiveSyncProvisioning::EasClientDeviceInformation();

	ret["cpu.vendor"] = get_cpu_model();
	ret["cpu.cores"] = to_string(std::thread::hardware_concurrency());
	ret["manufacturer"] = GameSparks::Core::wstring_to_utf8(deviceInfo->SystemManufacturer->Data());
	ret["os.name"] = GameSparks::Core::wstring_to_utf8(deviceInfo->OperatingSystem->Data());
	ret["model"] = GameSparks::Core::wstring_to_utf8(deviceInfo->SystemProductName->Data());
	ret["os.version"] = "RT";
	//ret["resolution"] = get_display_resolution();

	return ret;
}

#elif defined(_DURANGO)
#include "winbase.h"
#include <thread>
gsstl::map<gsstl::string, gsstl::string> gs_get_device_stats()
{
	gsstl::map<gsstl::string, gsstl::string> ret;

	ret["manufacturer"] = "Microsoft";
	ret["model"] = "Xbox One";

	ret["cpu.vendor"] = "AMD";
	ret["cpu.cores"] = to_string(std::thread::hardware_concurrency());

	ret["os.name"] = "DurangoOS";

	SYSTEMOSVERSIONINFO ver;
	GetSystemOSVersion(&ver);

	ret["os.version"] =
		to_string(int(ver.MajorVersion)) + "." +
		to_string(int(ver.MinorVersion)) + "." +
		to_string(int(ver.BuildNumber)) + "." +
		to_string(int(ver.Revision));

	MEMORYSTATUSEX memoryStatus;
	memoryStatus.dwLength = sizeof(memoryStatus);
	if (GlobalMemoryStatusEx(&memoryStatus))
	{
		ret["memory"] = to_string(memoryStatus.ullTotalPhys / 1024 / 1024 / 1024) + " GB";
	}
	else
	{
		ret["memory"] = "8 GB";
	}

	//ret["resolution"] = get_display_resolution();

	return ret;
}
#endif
#endif /* WIN32 */


#if defined(__ORBIS__)
#include <thread>
#include <sdk_version.h>
#include <iomanip>

std::map<std::string, std::string> gs_get_device_stats()
{
	std::map<std::string, std::string> ret;

	ret["manufacturer"] = "Sony";
	ret["model"] = "PS4";
	ret["memory"] = "8 GB";
	ret["os.name"] = "ORBIS";

	std::stringstream ss;
	ss << std::hex
		<< std::setfill('0')
		<< std::setw(2) << ((SCE_ORBIS_SDK_VERSION >> (6 * 4)) & 0xff) << "."
		<< std::setw(3) << ((SCE_ORBIS_SDK_VERSION >> (3 * 4)) & 0xfff) << "."
		<< std::setw(3) << ((SCE_ORBIS_SDK_VERSION >> (0 * 4)) & 0xfff);
	ret["os.version"] = ss.str();
	ret["cpu.cores"] = to_string(std::thread::hardware_concurrency());
	ret["cpu.vendor"] = "AMD";
	//ret["resolution"] = "Sony";
	return ret;
}
#endif
