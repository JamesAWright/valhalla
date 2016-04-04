#ifndef VALHALLA_ODIN_UTIL_H_
#define VALHALLA_ODIN_UTIL_H_

#include <vector>
#include <string>
#include <unordered_map>

#include <boost/property_tree/ptree.hpp>

#include <valhalla/proto/directions_options.pb.h>
#include <valhalla/odin/narrative_dictionary.h>

namespace valhalla {
namespace odin {

/**
 * Returns the specified item surrounded with quotes.
 * @param item  specified text to surround with quotes
 * @return the specified item surrounded with quotes.
 */
std::string GetQuotedString(const std::string& item);

bool IsSimilarTurnDegree(uint32_t path_turn_degree,
                         uint32_t intersecting_turn_degree, bool is_right,
                         uint32_t turn_degree_threshold = 30);

DirectionsOptions GetDirectionsOptions(const boost::property_tree::ptree& pt);

/**
 * Get the time from the inputed date.
 * date_time is in the format of 2015-05-06T08:00
 * @param   date_time in the format of 2015-05-06T08:00
 * @param   locale
 * @return  Returns the formated time based on the locale.
 */
std::string get_localized_time(const std::string& date_time,
                               const std::string& locale);

/**
 * Get the date from the inputed date.
 * date_time is in the format of 2015-05-06T08:00
 * @param   date_time in the format of 2015-05-06T08:00
 * @param   locale
 * @return  Returns the formated date based on the locale.
 */
std::string get_localized_date(const std::string& date_time,
                               const std::string& locale);

/**
 * Returns locale strings mapped to NarrativeDictionaries containing parsed narrative information
 *
 * @return the map of locales to NarrativeDictionaries
 */
using locales_singleton_t = std::unordered_map<std::string, NarrativeDictionary>;
const locales_singleton_t& get_locales();

/**
 * Returns locale strings mapped to json strings defining the dictionaries
 *
 * @return the map of locales to json strings
 */
const std::unordered_map<std::string, std::string>& get_locales_json();

}
}
#endif  // VALHALLA_ODIN_UTIL_H_
