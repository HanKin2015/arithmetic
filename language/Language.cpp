#include <stdio.h>
#include <stdlib.h>
#include "Language.h"
#include "Languages.h"

#define Implement_func(x) char *Language::get_##x()\
        {                               \
            return this->context.x;        \
        }

Language::Language()
{
    this->type =LANGUAGE_CHINESE;
    this->setContext();
}

Language::Language(int t)
{
    this->type=t;
    this->setContext();
}

void Language::setContext()
{
    switch(this->type)
    {
        case(LANGUAGE_CHINESE):
            set_CN_context(&context);
            break;
        case(LANGUAGE_ENGLISH):
            set_EN_context(&context);
            break;
        case(LANGUAGE_CHINESE_T):
            set_CN_T_context(&context);
            break;
        default:
            set_CN_context(&context);
    }
}

 void Language::setLanguageType(int t){
     this->type=t;
     this->setContext();
 }
/*实现相应的文本获取函数*/
Implement_func(start)
Implement_func(stop)
Implement_func(input)
Implement_func(clear)
Implement_func(second)
Implement_func(score)
Implement_func(submit)
Implement_func(generate)
Implement_func(file)
Implement_func(openfile)
Implement_func(copyfile)
Implement_func(exit)
Implement_func(language)
Implement_func(help)
Implement_func(params)
Implement_func(about)
Implement_func(record)
Implement_func(history)
Implement_func(mtime)
Implement_func(unit)
Implement_func(reset)
Implement_func(formula)
Implement_func(answer)
Implement_func(uinput)
