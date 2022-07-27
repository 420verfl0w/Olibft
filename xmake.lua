set_objectdir("build-int/$(os)_$(arch)")
set_targetdir("build/$(os)_$(arch)")

add_rules("mode.debug", "mode.release")

set_toolchains("fasm")

set_warnings("allextra", "error")
set_optimize("fastest")

set_project("olibft")
set_version("0.0.1")

target("olibft_core")
	set_prefixname("")
    set_kind("static")
    add_files("src/strings/*.asm", "src/utils/*.asm")
target_end()

target("olibft_maths")
	set_default(false)
	set_prefixname("")
    set_kind("static")
    add_files("src/maths/*.asm")
target_end()

target("olibft_sys")
	set_default(false)
	set_prefixname("")
    set_kind("static")
    add_files("src/sys/*.c", "src/syscalls/*.asm")
target_end()

target("all")
	set_default(false)
	set_kind("phony")
	add_deps("olibft_core")
	add_deps("olibft_maths")
	add_deps("olibft_sys")
target_end()
