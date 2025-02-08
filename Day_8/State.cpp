//
// Created by DarsenOP on 2/8/25.
//

#include <iostream>
#include <string>

/*Too many switches and it gets pretty complicated*/



// class Member
// {
//     enum Membership { FREE, BASIC, PREMIUM };
//     Membership type;
//
//     int current_downloads;
//
//     std::string name;
//
// public:
//     Member(const std::string& n) : name(n), type(FREE), current_downloads(0) {}
//
//     void upgrade()
//     {
//         switch (type) {
//             case FREE:
//                 std::cout << "Free, upgrading to basic" << std::endl;
//                 type = BASIC;
//                 break;
//             case BASIC:
//                 std::cout << "Basic, upgrading to premium" << std::endl;
//                 type = PREMIUM;
//                 break;
//             case PREMIUM:
//                 std::cout << "You are at the highest level!" << std::endl;
//                 break;
//         }
//     }
//
//     bool can_download()
//     {
//         switch (type) {
//             case FREE:
//                 return current_downloads < 1;
//             case BASIC:
//                 return current_downloads < 5;
//             case PREMIUM:
//                 return true;
//         }
//     }
//
//     bool download()
//     {
//
//     }
// };


/* Using State Idiom to Avoid Switches */

class Membership
{
    std::string _name;
public:
    explicit Membership(const std::string& n) : _name(n) {}
    virtual ~Membership() = default;

    [[nodiscard]] const std::string& GetName() const { return _name; }

    [[nodiscard]] virtual int downloads_per_day() const = 0;
    [[nodiscard]] virtual Membership* upgrade() const = 0;
};

class PremiumMember final : public Membership
{
public:
    PremiumMember(): Membership("Premium") {}

    [[nodiscard]] int downloads_per_day() const override
    {
        return 99999999;
    }

    [[nodiscard]] Membership* upgrade() const override
    {
        std::cout << "You are on the highest level!" << std::endl;
        return const_cast<PremiumMember*>(this);;
    }
};

class BasicMember final : public Membership
{
public:
    BasicMember(): Membership("Basic") {}

    [[nodiscard]] int downloads_per_day() const override
    {
        return 5;
    }

    [[nodiscard]] Membership* upgrade() const override
    {
        std::cout << "Basic, upgrade to premium" << std::endl;
        return new PremiumMember();
    }
};

class FreeTier final : public Membership
{
public:
    FreeTier(): Membership("Free") {}

    [[nodiscard]] int downloads_per_day() const override
    {
        return 1;
    }

    [[nodiscard]] Membership* upgrade() const override
    {
        std::cout << "Free, upgrade to basic" << std::endl;
        return new BasicMember();
    }
};

class Member
{
    Membership* _role;
    std::string _name;
    int current_downloads;
public:
    explicit Member(const std::string& n) : _name(n), current_downloads(0), _role(new FreeTier()) {}

    [[nodiscard]] const std::string& GetName() const { return _name; }

    [[nodiscard]] bool can_download() const
    {
        return (_role->downloads_per_day() > current_downloads);
    }

    bool download()
    {
        if (can_download()) {
            ++current_downloads;
            return true;
        }

        return false;
    }

    void upgrade()
    {
        _role = _role->upgrade();
    }
};