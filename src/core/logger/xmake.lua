target("logger")
    set_kind("shared")
    add_headerfiles("*.h")
    add_files(
        "logger.cpp"
        ) 

    after_build(function (target)
        print("target name: %s", target:name())
        os.exec("echo %s", target:targetfile())
    end)
