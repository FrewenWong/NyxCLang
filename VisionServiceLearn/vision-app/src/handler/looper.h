
#ifndef VISION_SERVICE_LEARN_LOOPER_H
#define VISION_SERVICE_LEARN_LOOPER_H

/**
 * 定义命名空间name：handler
 */
namespace handler {
    // TODO 直接在命名空间里面，这个相当于类对象的声明？？
    // 声明Message对象
    class Message;

    // 声明Handler对象
    class Handler;

    class MessageQueue;

    /**
     * Looper对象的定义
     */
    class Looper {
    public:
        Looper();

        ~Looper();

    private:
        MessageQueue *mQueue;
    };

}

#endif //VISION_SERVICE_LEARN_LOOPER_H
