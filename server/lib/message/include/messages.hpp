#pragma once

#include <string>
#include <string_view>
#include <boost/property_tree/ptree.hpp>

constexpr std::string_view MSG_END = "\n\r\n\r";

class Message {
public:
    virtual ~Message() = 0;

    static std::string message_ptree(boost::property_tree::ptree const &request);
};

class MessageClient : public Message {
public:
    static std::string msg();

    static std::string disconnect();

    static std::string create_room();

    static std::string error();

    static std::string join_room(const size_t &room_id);

};

class MessageServer : public Message {
public:
    static std::string start_game(const size_t &id);

    static std::string start_game_failed();

    static std::string create_room_failed();

    static std::string create_room_done(const int &id);

    static std::string connected(const std::string &ids, const std::string &ips, const int &role,
                                 const bool &is_alive, const bool &is_sleep,
                                 const std::string &status, const int &current_id,
                                 const bool &is_day);

    static std::string msg(const std::string &ids, const std::string &names, const int &id);

    static std::string join_room_done(const size_t &id);

    static std::string join_room_failed(const int &id);

    static std::string leave_room_done();

    static std::string finish_game();

    static std::string day_accepted();

    static std::string nigth_accepted(const int &killed_id);

    static std::string vote_accepted(const int &id);
};