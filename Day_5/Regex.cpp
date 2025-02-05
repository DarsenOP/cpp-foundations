//
// Created by DarsenOP on 2/5/25.
//

#include <iomanip>
#include <iostream>
#include <regex>

bool ValidateDate(const std::string& date);

int main()
{
    /* Regex Character Classes */

    // .        -> any single character (except newline)
    // \d       -> any digit (0-9)
    // \w       -> any word character (a-z, A-Z, 0-9, _)
    // \s       -> any whitespace character (space, tab, newline)
    // \D       -> any non-digit
    // \W       -> any non-word
    // \S       -> any non-whitespace

    /* Regex Quantifiers */

    // *        -> 0 or more repetitions
    // +        -> 1 or more repetitions
    // ?        -> 0 or 1 repetitions
    // {n}      -> exactly n repetitions
    // {n, }    -> at least n repetitions
    // {n, m}   -> between n and m repetitions

    /* Regex Anchors */

    // ^        -> start of the string
    // $        -> end of the string
    // \b       -> word boundary
    // \B       -> not a word boundary

    /* Regex Grouping & Capturing */

    // ()       -> capturing group (extracts part of the match)
    // (?:...)  -> non-capturing group (useful for grouping but not storing)
    // `        -> `

    /* Regex Functions */
    // Matching a Pattern           -> std::regex_match
    // Finding a Substring          -> std::regex_search
    // Extracting Multiple Matches  -> std::sregex_iterator
    // Replacing Text               -> std::regex_replace

    /* Creating a Regex */
    std::string checking_string{};
    std::regex pattern(R"EXPRESSION");

    // Example with date validation
    std::string date{"2002/12.12"};
    ValidateDate(date);

    return 0;
}

bool ValidateDate(const std::string& date)
{
    auto isLeapYear = [](int year) {
        return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
    };

    const std::regex format(R"(^(\d{4})([-/\.])(\d{1,2})\2(\d{1,2})$)");

    std::smatch match;
    if (!std::regex_match(date, match, format))
        return false;

    const int year = std::stoi(match[1].str());
    const int month = std::stoi(match[3].str());
    const int day = std::stoi(match[4].str());

    constexpr int MIN_YEAR = 1900;
    if (year < MIN_YEAR || month < 1 || month > 12)
        return false;

    static const std::vector<int> days_in_month = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    const int max_days = days_in_month[month] + (isLeapYear(year) && month == 2 ? 1 : 0);
    if (day < 1 || day > max_days)
        return false;

    std::ostringstream normalized_date;
    normalized_date << std::setfill('0') << std::setw(4) << year << "-"
                                            << std::setw(2) << month << "-"
                                            << std::setw(2) << day;

    date = normalized_date.str();
    return true;
}