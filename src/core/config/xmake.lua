target("config")
    set_kind("shared")
    add_headerfiles("include/config.h")
    add_files(
        "src/config.cpp"
        ) 
    add_packages("nlohmann_json")
    after_build(function (target)
        print("target name: %s", target:name())
        os.exec("echo %s", target:targetfile())
    end)
