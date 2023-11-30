#include "catch.hpp"

#include "hash_dictionary.hpp"

#include <iostream> // for debugging
#include <sstream>  // for std::ostringstream
#include <string>   // for std::string

typedef unsigned int KeyType;
typedef std::string ValueType;
typedef std::size_t (*FunctionType)(const KeyType &key);
typedef HashDictionary<KeyType, ValueType, FunctionType> DictionaryType;

std::size_t hash(const KeyType& key) { return key; }

TEST_CASE("Basic Tests", "[Dictionary]") {
	//To DO
	DictionaryType dictionary(hash);

	REQUIRE_NOTHROW(dictionary.add(20, "twenty"));
	REQUIRE_FALSE(dictionary.isEmpty());
	REQUIRE(dictionary.size() == 1);

	REQUIRE_NOTHROW(dictionary.add(2, "two"));
	REQUIRE_NOTHROW(dictionary.add(5, "five"));
	REQUIRE_NOTHROW(dictionary.add(50, "fifty"));
	REQUIRE(dictionary.contains(2));
	REQUIRE(dictionary.contains(20));
	REQUIRE(dictionary.contains(50));
	REQUIRE_FALSE(dictionary.contains(1));
	REQUIRE(dictionary.get(2) == "two");
	REQUIRE_NOTHROW(dictionary.remove(2));
	REQUIRE_NOTHROW(dictionary.remove(5));
	REQUIRE_NOTHROW(dictionary.remove(20));
	REQUIRE_NOTHROW(dictionary.remove(50));
	REQUIRE(dictionary.isEmpty());
}

TEST_CASE("Test large Dictionary", "[Dictionary]") {
	//To Do
	DictionaryType dictionary(hash);

	for (KeyType k = 0; k < 1000; k++) {
		std::ostringstream ss;
		ss << k;
		INFO(k);
		REQUIRE_NOTHROW(dictionary.add(k, ss.str()));
	}

	for (KeyType k = 0; k < 1000; k++) {
		std::ostringstream ss;
		ss << k;
		INFO(k);
		REQUIRE(dictionary.contains(k));
	}
}

