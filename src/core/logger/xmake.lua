target("logger")
    set_kind("shared")
    add_headerfiles("include/*.h")
    add_files(
        "src/logger.cpp"
        ) 

    after_build(function (target)
        print("target name: %s", target:name())
        os.exec("echo %s", target:targetfile())
    end)
