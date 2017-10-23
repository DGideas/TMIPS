// TMIPS interface header file
// Used for multilanguage compile
// Available language(using ISO 639-1 and ISO-3166-1):
// zh_CN 中文/中国大陆
// en_US
// dgideas@outlook.com

#define zh_CN

#ifdef zh_CN
	#define INTERFACE_WORD_VERSION "版本"
	#define INTERFACE_WORD_BIT "位元"
	#define INTERFACE_HINT "使用--help获得更多信息，使用--version查看版本信息"
	#define INTERFACE_ERROR_NO_INPUT ""
#endif

#ifdef en_US
	#define INTERFACE_WORD_VERSION "version"
	#define INTERFACE_WORD_BIT "bit"
	#define INTERFACE_HINT "lookup more information by --help,\
	 using --version to display version information"
	#define INTERFACE_HEADER 
	#define INTERFACE_ERROR_NO_INPUT 
#endif