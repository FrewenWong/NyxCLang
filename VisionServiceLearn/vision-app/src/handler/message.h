//
// Created by Frewen.Wong on 2021/6/29.
//

#ifndef VISION_SERVICE_MESSAGE_H
#define VISION_SERVICE_MESSAGE_H

namespace handler {

    class Message {
    public:
        int what;
        int arg1;
        int arg2;

        /**
         * 构造函数
         */
        Message();

        /**
         * 隐式类型转换 (构造函数的隐式调用)
         * Message的构造函数传入单个int值最好加上explicit。避免隐式转换，产生不可用预期的隐式转换和复制实例化
         * https://zhuanlan.zhihu.com/p/52152355
         * @param what
         */
        explicit Message(int what);

        /**
         * @param what
         * @param handler 入参为Handler指针
         */
        Message(int what, Handler *handler);

        Message(int what, int arg1, int arg2);

        Message(int what, int arg1, int arg2, Handler *handler);

        ~Message();

        /**
         * obtain返回Message对象的指针
         * @return
         */
        static Message *obtain();

        static void recycle(Message *msg) {
            delete msg;
        }

    };
}


#endif //VISION_SERVICE_MESSAGE_H
