-- 在 xmake.lua 中设置工具链为 LLVM
add_requires("llvm", {optional = true})
add_rules("mode.debug", "mode.release")
set_languages("cxx17")
set_toolset("cc", "clang")
set_toolset("cxx", "clang++")
set_toolset("ld", "clang++")

target("Learn_OpenCV")
    set_kind("binary")
    add_files("src/07_01_image_video_loading.cpp")

    -- 设置自行编译的OpenCV的头文件路径
    add_includedirs("/usr/local/opencv/include/opencv4", "/usr/local/opencv/include")

    -- 设置自行编译的OpenCV的库文件路径
    add_linkdirs("/usr/local/opencv/lib")

    -- 指定要链接的OpenCV库
    add_links("opencv_core", "opencv_imgproc", "opencv_highgui", "opencv_imgcodecs","opencv_videoio")

    -- 设置rpath
    if is_plat("macosx") then
        add_rpathdirs("/usr/local/opencv/lib")
    elseif is_plat("linux") then
        -- 在Linux上，使用$ORIGIN作为rpath的一部分
        add_rpathdirs("$ORIGIN/../lib")
    end
