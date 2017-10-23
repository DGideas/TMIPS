// TMIPS interface header file
// Used for multilanguage compile
// Available language(using ISO 639-1 and ISO-3166-1):
// zh_CN
// en_US
// dgideas@outlook.com

#define zh_CN

#ifdef zh_CN
	#define LANGUAGE_LOCALNAME "中文/中国大陆"
	#define INTERFACE_WORD_VERSION "版本"
	#define INTERFACE_WORD_RUN_ON "运行于"
	#define INTERFACE_WORD_BIT "位元"
	#define INTERFACE_HINT "键入\"--help\"或者\"--version\"查看更多信息。"
	#define INTERFACE_ERROR_NO_INPUT ""
#endif

#ifdef en_US
	#define LANGUAGE_LOCALNAME "English/United States"
	#define INTERFACE_WORD_VERSION "version"
	#define INTERFACE_WORD_RUN_ON "on"
	#define INTERFACE_WORD_BIT "bits"
	#define INTERFACE_HINT "Type \"--help\" or \"--version\" for more information."
	#define INTERFACE_HEADER 
	#define INTERFACE_ERROR_NO_INPUT 
#endif