## c++11中规定，静态成员变量必须在类外初始化

## TODO : 线程问题

## TODO: 饿汉懒汉

## static 设置成局部 还是成员变量，有何影响

局部static是线程安全的，代替std::call_once

将关键字static用于类的数据成员,数据成员将在所有的实例间共享

局部变量时，该变量的值将在两次调用之间保持不变

https://huanyingtianhe.github.io/2018/01/22/c-%E4%B8%AD%E7%9A%84static%E5%8F%98%E9%87%8F%E5%92%8C%E7%BA%BF%E7%A8%8B%E5%AE%89%E5%85%A8/

## TODO C++函数内的静态变量初始化以及线程安全问题

https://www.zhihu.com/question/267013757

https://stackoverflow.com/questions/8102125/is-local-static-variable-initialization-thread-safe-in-c11

https://www.cnblogs.com/william-cheung/p/4831085.html

https://www.coder.work/article/1731986

https://blog.csdn.net/imred/article/details/89069750

https://blog.csdn.net/yuhaiyang457288/article/details/50420073

## 仅在绝对必要时才使用单例模式
