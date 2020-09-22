#include <std_include.hpp>

#include "game_console.hpp"
#include "scheduler.hpp"

#include "game/game.hpp"
#include "game/dvars.hpp"
#include "discord/discord.h"

#include "utils/hook.hpp"
#include "utils/string.hpp"
#include <string.h>

namespace 
{
	discord::Core* core{};
	auto result = discord::Core::Create(757965986954477690, DiscordCreateFlags_Default, &core);
	discord::Activity activity{};

	int get_player_count() {
		int maxclients = game::native::Dvar_FindVar("sv_maxclients")->current.integer;
		int count = 0;
		for (int i = 0; i < maxclients; i++) {
			if (game::native::mp::g_entities[i].s.entityType) {
				count++;
			}
		}
		return count;
	}

	void tick() {
		if (game::is_mp())
		{
			if (game::native::SV_Loaded())
			{
				activity.GetParty().GetSize().SetCurrentSize(get_player_count());
				activity.GetParty().GetSize().SetMaxSize(game::native::Dvar_FindVar("sv_maxclients")->current.integer);

				activity.SetDetails("Multiplayer");
				activity.SetState(utils::string::va("Playing on %s", game::native::Dvar_FindVar("mapname")->current.string));
			}
			else
			{
				activity.SetDetails("Multiplayer");
				activity.SetState("In Menus");
			}
		}
		else
		{
			activity.SetDetails("Singleplayer");
		}

		activity.GetAssets().SetLargeImage("iw6x");

		core->ActivityManager().UpdateActivity(activity, [](discord::Result result) {});
		::core->RunCallbacks();
	}
}


class discord_rpc final : public module
{
public:
	void post_unpack() override
	{
		activity.GetTimestamps().SetStart(std::time(0));
		scheduler::loop(tick, scheduler::pipeline::renderer);
	}
};

REGISTER_MODULE(discord_rpc);