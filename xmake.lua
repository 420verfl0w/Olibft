----------------------------------------
--
-- Author	: maldavid
-- Date		: 2022-07-27 22-19-23
-- Filename	: xmake
--
----------------------------------------

set_objectdir("build-int/$(os)_$(arch)")
set_targetdir("build/$(os)_$(arch)")

add_rules("mode.debug", "mode.release")

set_toolchains("fasm")

set_warnings("allextra", "error")
set_optimize("fastest")

set_project("olibft")
set_version("0.0.1")

add_includedirs("includes")

local banner = [[
	 ▒█████   ██▓███  ▓█████  ███▄    █  ██▓     ██▓ ▄▄▄▄     █████▒▄▄▄█████▓
	▒██▒  ██▒▓██░  ██▒▓█   ▀  ██ ▀█   █ ▓██▒    ▓██▒▓█████▄ ▓██   ▒ ▓  ██▒ ▓▒
	▒██░  ██▒▓██░ ██▓▒▒███   ▓██  ▀█ ██▒▒██░    ▒██▒▒██▒ ▄██▒████ ░ ▒ ▓██░ ▒░
	▒██   ██░▒██▄█▓▒ ▒▒▓█  ▄ ▓██▒  ▐▌██▒▒██░    ░██░▒██░█▀  ░▓█▒  ░ ░ ▓██▓ ░ 
	░ ████▓▒░▒██▒ ░  ░░▒████▒▒██░   ▓██░░██████▒░██░░▓█  ▀█▓░▒█░      ▒██▒ ░ 
	░ ▒░▒░▒░ ▒▓▒░ ░  ░░░ ▒░ ░░ ▒░   ▒ ▒ ░ ▒░▓  ░░▓  ░▒▓███▀▒ ▒ ░      ▒ ░░   
	  ░ ▒ ▒░ ░▒ ░      ░ ░  ░░ ░░   ░ ▒░░ ░ ▒  ░ ▒ ░▒░▒   ░  ░          ░    
	░ ░ ░ ▒  ░░          ░      ░   ░ ░   ░ ░    ▒ ░ ░    ░  ░ ░      ░      
	    ░ ░              ░  ░         ░     ░  ░ ░   ░                       
                                                      ░                  

				OpenLibft Created by 42Angouleme
				[ Version : 0.0.1 (alpha) ] 

]]

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
	before_build(function (target)
        print(string.format("\27[38;5;45m%s\27[0m", banner))
    end)

	set_default(false)
	set_kind("phony")
	add_deps("olibft_core")
	add_deps("olibft_maths")
	add_deps("olibft_sys")
target_end()