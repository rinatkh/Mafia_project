#pragma once

#include "gameroom.hpp"
#include "base.hpp"
#include "communication.hpp"
#include "PlayRoom.h"

#include <string>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/property_tree/ptree.hpp>

constexpr size_t MAX_USERS = 4;

namespace net {

    class GameConnection {
    public:
        explicit GameConnection(std::shared_ptr<Communication> &communication);

        int join_to_game(std::shared_ptr<Communication> &communication);

        GameRoom game;

        boost::atomic<bool> is_gaming;
        boost::atomic<bool> is_remove;

    private:

        void handle_read(std::shared_ptr<Communication> communication);

        void handle_write(std::shared_ptr<Communication> communication);

        void handle_request(std::shared_ptr<Communication> communication);

        void handle_game_status(std::shared_ptr<Communication> communication);

        void disconnect(std::shared_ptr<Communication> communication);

        void handle_error(std::shared_ptr<Communication> communication);

        void handle_admin_request(std::shared_ptr<Communication> communication);

        static void join_to_game_failed(std::shared_ptr<Communication> communication);

        static void create_room_failed(std::shared_ptr<Communication> communication);

        void game_delete();

        void handle_leave(std::shared_ptr<Communication> communication);

        void handle_ping(std::shared_ptr<Communication> communication);

        void handle_game_day(std::shared_ptr<Communication> communication);

        void handle_vote(std::shared_ptr<Communication> communication);

        void handle_vote_mafia(std::shared_ptr<Communication> communication);

        void handle_game_nigth(std::shared_ptr<Communication> communication);

    private:
        boost::atomic<bool> is_day;
        boost::asio::io_context &context;

        std::vector<std::shared_ptr<Communication>> communications;

        std::vector<int> votes;
        std::vector<int> votes_mafia;

        PlayRoom game_room;
        std::mutex game_mutex;
    };
}
