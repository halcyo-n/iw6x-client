discordrpc = {
	source = path.join(dependencies.basePath, "discord-rpc"),
	rapidjson = path.join(dependencies.basePath, "rapidjson"),
}

function discordrpc.import()
	links { "discord-rpc" }
	discordrpc.includes()
end

function discordrpc.includes()
	includedirs {
		path.join(discordrpc.source, "include"),
		path.join(discordrpc.rapidjson, "include"),
	}
end

function discordrpc.project()
	project "discord-rpc"
		language "C++"

		discordrpc.includes()

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
		}

		warnings "Off"
		kind "StaticLib"
end

table.insert(dependencies, discordrpc)
