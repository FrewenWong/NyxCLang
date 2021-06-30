//
// Created by Frewen.Wong on 2021/6/17.
//

#ifndef VISION_SERVICE_VISION_H
#define VISION_SERVICE_VISION_H


// 定义VisionApp的版本号
// 8-bit unsigned int, min: 0, max: 255
#define VISION_VERSION_MAJOR 0

// 8-bit unsigned int, min: 0, max: 255
#define VISION_VERSION_MINOR 1

// 8-bit unsigned int, min: 0, max: 255
#define VISION_VERSION_PATCH 1

//
#define VISION_STRING(x) #x
#define VISION_TOSTRING(x) VISION_STRING(x)

// get version string
#define VISION_VERSION_STR \
        VISION_TOSTRING(VISION_VERSION_MAJOR) "." \
        VISION_TOSTRING(VISION_VERSION_MINOR) "." \
        VISION_TOSTRING(VISION_VERSION_PATCH)


#endif //VISION_SERVICE_VISION_H
