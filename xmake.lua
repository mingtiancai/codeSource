set_project("codeSource")

-- set xmake minimum version
set_xmakever("2.6.7")

add_rules("mode.debug", "mode.release")

set_languages("c++17")
set_languages("c11")

add_requires("boost", {configs = {all = true}})

-- internal library 
add_includedirs("src/core/logger/include")

includes("src")