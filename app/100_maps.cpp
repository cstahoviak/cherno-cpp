/*
 * Video #100: Maps
 */

// Needed for uint64_t
#include <cstddef>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

struct CityRecord
{
  std::string name;
  uint64_t population;
  double latitude;
  double longitude;

  // To use a CityRecord as the key in a std::map (an ordered map), we need to
  // implement the less than operator so that two elements of the map can be
  // compared. Note that both the lhs and rhs of the comparison need to be
  // marked as const.
  // The less than operator not only plays the role of comparison for an ordered
  // map, it also defines a unique key within the map. So in this case, if two
  // cities have the same population, then this can cause problems.
  // What problems?
  bool operator<(const CityRecord& other) const {
    return population < other.population;
  }
};

// Define a "template specialization" for std::hash within the std namespace
// that is "specialized" by the type (CityRecord) that we'll use as the map's
// key.
namespace std 
{
  // A template "specialization" uses an empty template argument
  template<>
  struct hash<CityRecord>
  {
    // Overload the call operator and return a 64 bit uint (size_t).
    size_t operator()(const CityRecord& key)
    {
      // Define the hash function here. 
      return hash<std::string>()(key.name);
    }
  };
}

using CityMap = std::unordered_map<std::string, CityRecord>;
std::optional<uint64_t> get_population(const CityMap& map, std::string key) {
  // Check to see see if the key exists
  if (map.find(key) != map.end()) {
      // Because no const version of the index operator [] exists for maps,
      // we have to use at() to retrieve the element.
      return map.at(key).population;
  }

  // The method above performs two lookups: one for find() and a second for
  // at(). We can avoid the second (unecessary) lookup by saving the iterator
  // returned by find(). This method of using find() and at() should always be
  // preferred.
  if (const auto it = map.find(key); it != map.end()) {
    return (it->second).population;
  }

  // TODO: Return a "key not found error" instead.
  return std::nullopt;
}

int main() {
  // Create an unordered map (dictionary)
  std::unordered_map<std::string, CityRecord> cities;
  cities["Berlin"] = {"Berlin", 5'000'000, 2.4, 9.4};

  // Retrieve the element
  CityRecord& berlin = cities["Berlin"];

  // Use a functon that expects a const map
  auto pop = get_population(cities, "Berlin");
  if (pop.has_value()) {
    std::cout << "Berlin population: " << pop.value() << std::endl;
  }

  // The following will return a reference to the value stored by the "Boulder"
  // key if it exists (which it doesn't), otherwise, it will create the
  // "Boulder" key with a possibly non-initialized CityRecord instance.
  CityRecord& boulder = cities["Boulder"];

  // Alternatively, we can create the CityRecord object in the local stack
  // frame, and then copy it into the map, but, as always, we want to avoid
  // unecessary copies.
  CityRecord denver;
  denver.name = "Denver";
  denver.population = 1;
  cities["Denver"] = denver;

  // If true, the cities "Albuquerque", "El Paso" and "Redmond" will have unique
  // populations and will be added as unique elements of the ordered map called
  // 'founded'. If false, all three cities will have the same population, and
  // since CityRecord::population is used in our implementation of the less than
  // operator, a CityRecord's poulation determines its uniqueness in the map,
  // and only "Albuquerque" will be added to the ordered map (std::map).
  bool MAKE_POPULATION_UNIQUE = false;

  // Add some more cities
  std::vector<std::string> city_names = {"Albuquerque", "El Paso", "Redmond"};
  int i = 0;
  for (std::string& name : city_names) {
    // Create the CityRecord in place and set it's data
    CityRecord& record = cities[name];
    record.name = name;
    record.population = MAKE_POPULATION_UNIQUE ? 100 + i++ : 100;
    record.latitude = 0.0;
    record.longitude = 0.0;
  }

  // Iterate over a map and use structured bindings (in C++!7) to access the
  // key-value pairs.
  std::cout << "\nIterating over unordered map:" << std::endl;
  for (auto& [name, record] : cities) {
    std::cout << name << "\n\tpopulation: " << record.population << std::endl;
  }

  // Remove an element from the map.
  cities.erase("Denver");

  // Create an ordered map that uses the CityRecord type as its key
  std::map<CityRecord, uint64_t> founded_map;

  // Add some elements to the map (some with identical population)
  founded_map[cities["Berlin"]] = 1650;
  for (std::string& name : city_names) {
    // NOTE that if we attempt to add a new element that evaluates as "equal to"
    // another element according to our custom implementation of the less than
    // operator, then that new element will not be added.
    founded_map[cities[name]] = 1800;
  }

  // Iterate over a map and use structured bindings (in C++!7) to access the
  // key-value pairs.
  std::cout << "\nIterating over ordered map:" << std::endl;
  for (auto& [record, year] : founded_map) {
    std::cout << record.name << "\n\tpopulation: " << record.population << 
      std::endl;
  }
}