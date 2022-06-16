set_project("codeSource")

-- set xmake minimum version
set_xmakever("2.6.7")

add_rules("mode.debug", "mode.release")

set_languages("c++17")
set_languages("c11")

add_requires("boost", {configs = {
    serialization = true,
    random = true,
    filesystem = true,
    fiber = true,
    test = true,
    program_options = true,
    all = true,
    contract = true,
    regex = true,
    thread = true,
    log = true,
    nowide = true,
    mpi = true,
    pic = true,
    system = true,
    date_time = true,
    exception = true,
    debug = true,
    type_erasure = true,
    chrono = true,
    python = true,
    graph = true,
    wave = true,
    iostreams = true,
    context = true,
    json = true,
    locale = true,
    multi = true,
    math = true,
    timer = true,
    container = true,
    graph_parallel = true,
    stacktrace = true,
    coroutine = true,
    atomic = true,
    shared = true}})

add_requires("spdlog")
add_requires("nlohmann_json")

-- internal library 
add_includedirs("src/core/logger/include")
add_includedirs("src/core/config/include")

includes("src")