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
    add_files("src/strings/*.asm", "src/utils/*.asm", "src/strings/**/*.asm")
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
	set_kind("static")
	set_basename("olibft")
	set_prefixname("")
    add_files("src/sys/*.c", "src/syscalls/*.asm")
    add_files("src/maths/*.asm")
    add_files("src/strings/*.asm", "src/utils/*.asm", "src/strings/**/*.asm")
target_end()

target("clean")
	set_kind("phony")
	set_default(false)
	on_load(function(target)
		os.rm("build-int")
    end);
target_end()

target("fclean")
	set_kind("phony")
	set_default(false)
	on_load(function(target)
		os.rm("build-int")
		os.rm("build")
    end);
target_end()
