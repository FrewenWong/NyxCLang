//
// Created by Frewen.Wong on 2021/3/25.
//

#ifndef VISION_LEARN_MERGE_TOOL_H
#define VISION_LEARN_MERGE_TOOL_H


class MergeModelTool {
public:
    /**
     *
     * @param cfg_path
     * @param src_path
     * @param dest_path
     */
    MergeModelTool(std::string cfg_path, std::string src_path, std::string dest_path);

    /**
     * 析构函数
     */
    ~MergeModelTool();

};

#endif //VISION_LEARN_MERGE_TOOL_H
