#ifndef LANGUAGE_H
#define LANGUAGE_H

enum{
    LANGUAGE_CHINESE,
    LANGUAGE_ENGLISH,
    LANGUAGE_CHINESE_T,
}LANGUAGE_TYPE;
/*界面所需的文本*/
typedef struct {
    char *start;
    char *stop;
    char *input;
    char *submit;
    char *generate;
    char *second;
    char *clear;
    char *score;
    char *file;
	char *openfile;
	char *copyfile;
	char *exit;
	char *language;
	char *help;
	char *params;
	char *about;
    char *record;
    char *history;
    char *mtime;
    char *unit;
    char *reset;
    char *formula;
    char *answer;
    char *uinput;
}Language_Context;


#define Declare_func(x) char *get_##x();
class Language{
public:
    Language(int t);
    Language();
    void setLanguageType(int t);
    /*声明相应的文本获取函数*/
    Declare_func(start)
    Declare_func(stop)
    Declare_func(input)
    Declare_func(clear)
    Declare_func(second)
    Declare_func(score)
    Declare_func(submit)
    Declare_func(generate)
    Declare_func(file)
    Declare_func(openfile)
    Declare_func(copyfile)
    Declare_func(exit)
    Declare_func(language)
    Declare_func(help)
    Declare_func(params)
    Declare_func(about)
    Declare_func(record)
    Declare_func(history)
    Declare_func(mtime)
    Declare_func(unit)
    Declare_func(reset)
    Declare_func(formula)
    Declare_func(answer)
    Declare_func(uinput)
private:
    void setContext();
    int type;
    Language_Context context;
};

#endif // LANGUAGE_H
