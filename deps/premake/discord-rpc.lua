discordrpc = {
	source = path.join(dependencies.basePath, "discord-rpc"),
<<<<<<< HEAD
	rapidjson = path.join(dependencies.basePath, "rapidjson"),
=======
>>>>>>> 6f2ae9a0063a624b70d217e69567737386924f07
}

function discordrpc.import()
	links { "discord-rpc" }
	discordrpc.includes()
end

function discordrpc.includes()
	includedirs {
		path.join(discordrpc.source, "include"),
<<<<<<< HEAD
		path.join(discordrpc.rapidjson, "include"),
=======
>>>>>>> 6f2ae9a0063a624b70d217e69567737386924f07
	}
end

function discordrpc.project()
	project "discord-rpc"
		language "C++"

		discordrpc.includes()
<<<<<<< HEAD

		files {
			path.join(discordrpc.source, "src/serialization.h"),
			path.join(discordrpc.source, "src/serialization.cpp"),
			path.join(discordrpc.source, "src/rpc_connection.h"),
			path.join(discordrpc.source, "src/rpc_connection.cpp"),
			path.join(discordrpc.source, "src/msg_queue.h"),
			path.join(discordrpc.source, "src/dllmain.cpp"),
			path.join(discordrpc.source, "src/discord_rpc.cpp"),
			path.join(discordrpc.source, "src/discord_register_win.cpp"),
			path.join(discordrpc.source, "src/connection_win.cpp"),
=======
		rapidjson.import();

		files {
			path.join(discordrpc.source, "src/*.h"),
			path.join(discordrpc.source, "src/*.cpp"),
		}
		
		removefiles {
			path.join(discordrpc.source, "src/dllmain.cpp"),
			path.join(discordrpc.source, "src/*_linux.cpp"),
			path.join(discordrpc.source, "src/*_unix.cpp"),
			path.join(discordrpc.source, "src/*_osx.cpp"),
>>>>>>> 6f2ae9a0063a624b70d217e69567737386924f07
		}

		warnings "Off"
		kind "StaticLib"
end

table.insert(dependencies, discordrpc)
