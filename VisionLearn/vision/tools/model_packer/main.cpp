#include <iostream>

/**
 * 编译模型打包工具
 * @param args
 * @param argv
 * @return
 */
int main(int argc, char **argv) {

    std::cout << "============ 开始编译合并模型工具 ========argc:" << argc << std::endl;
    if (argc < 4) {
        std::cout
                << "Usage: merge_model_tool [config_path] [src_models_dir] [dest_model_dir] [server_ip] [server_user] [model_hub_root] [encrypt_type]"
                << std::endl
                << "encrypt_type = 0: None, 1: DES, 2: AES" << std::endl;
        return 0;
    } else {

    }

    std::cout << "============ 开始编译合并模型工具 ===========" << std::endl;

    auto cfg_path = argv[1];
    auto src_dir = argv[2];
    auto dest_dir = argv[3];
}