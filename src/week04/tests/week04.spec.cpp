#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <src/week04/week04.hpp>

using namespace annzy::week04;

TEST_CASE("week04::alliterationCorrect") {
    CHECK(alliterationCorrect("She swam to the shore."));
    CHECK(alliterationCorrect("He helps harness happiness."));
    CHECK(
        alliterationCorrect("Tanya took the tomatoes. Two times two is not "
                            "twenty."));
    CHECK(alliterationCorrect("There are tall tortoises in the zoo."));
    CHECK(alliterationCorrect("Nancy nimbly ran for the newts."));
    CHECK_FALSE(alliterationCorrect("Maybel manages money well."));
    CHECK_FALSE(alliterationCorrect("There are many animals in the zoo."));
    CHECK_FALSE(alliterationCorrect("Two times two is four."));
}

TEST_CASE("week04::seesaw") {
    CHECK(seesaw(3449) == "right");
    CHECK(seesaw(1143113) == "left");
    CHECK(seesaw(585585) == "balanced");
    CHECK(seesaw(11) == "balanced");
    CHECK(seesaw(111) == "balanced");
    CHECK(seesaw(1) == "balanced");
    CHECK(seesaw(5855) == "left");
    CHECK(seesaw(5558) == "right");
}

TEST_CASE("week04::progressDays") {
    CHECK(progressDays({3, 4, 1, 2}) == 2);
    CHECK(progressDays({10, 11, 12, 9, 10}) == 3);
    CHECK(progressDays({6, 5, 4, 3, 2, 9}) == 1);
    CHECK(progressDays({9, 9}) == 0);
    CHECK(progressDays({12, 11, 10, 12, 11, 13}) == 2);
}

TEST_CASE("week04::wurstIsBetter") {
    CHECK(wurstIsBetter("Sausage fests are like salami fests") == "Wurst fests "
                                                                  "are like "
                                                                  "Wurst "
                                                                  "fests");
    CHECK(wurstIsBetter("Add the kielbasa and the reserved potatoes and stir "
                        "through") == "Add the Wurst and the reserved potatoes "
                                      "and stir through");
    CHECK(wurstIsBetter("Salami sandwiches, salami and cheese, salami on "
                        "crackers— "
                        "I couldn't get enough of the salty, spicy sausage") ==
          "Wurst sandwiches, Wurst and cheese, Wurst on crackers— "
          "I couldn't get enough of the salty, spicy Wurst");
    CHECK(wurstIsBetter("sich die Wurst vom Brot nehmen lassen") == "sich die "
                                                                    "Wurst vom "
                                                                    "Brot "
                                                                    "nehmen "
                                                                    "lassen");
    CHECK(wurstIsBetter("Bratwurst and Rostbratwurst is a sausage made from "
                        "finely minced pork and beef and usually grilled and "
                        "served with sweet German mustard and a piece of bread "
                        "or hard roll. It can be sliced and made into "
                        "Currywurst "
                        "by slathering it in a catchup-curry sauce.") ==
          "Bratwurst and Rostbratwurst is a Wurst made from "
          "finely minced pork and beef and usually grilled and "
          "served with sweet German mustard and a piece of bread "
          "or hard roll. It can be sliced and made into Currywurst "
          "by slathering it in a catchup-curry sauce.");
    CHECK(wurstIsBetter("Il n’arrête pas de faire l’andouille") == "Il "
                                                                   "n’arrête "
                                                                   "pas de "
                                                                   "faire "
                                                                   "l’Wurst");
    CHECK(wurstIsBetter("Naem is a common way of preserving pork meat in "
                        "several "
                        "Southeast Asian countries, including Thailand, Laos, "
                        "Cambodia and Vietnam") == "Wurst is a common way of "
                                                   "preserving pork meat in "
                                                   "several "
                                                   "Southeast Asian countries, "
                                                   "including Thailand, Laos, "
                                                   "Cambodia and Vietnam");
    CHECK(wurstIsBetter("The chipper group over at Orangatang recently dropped "
                        "another wheel sensation; the Moronga") ==
          "The chipper group over at Orangatang recently dropped "
          "another wheel sensation; the Wurst");
    CHECK(wurstIsBetter("She put salami on urka") == "She put Wurst on urka");
    CHECK(wurstIsBetter("alami put salami on urka") == "alami put Wurst on "
                                                       "urka");
}

TEST_CASE("week04::reverse") {
    CHECK(reverse("Reverse") == "esreveR");
    CHECK(reverse("This is a typical sentence.") == "This is a lacipyt "
                                                    ".ecnetnes");
    CHECK(reverse("The dog is big.") == "The dog is big.");
    CHECK(reverse("Reverse the order of every word greater than or equal "
                  "to "
                  "five characters.") == "esreveR the redro of yreve word "
                                         "retaerg than or lauqe to five "
                                         ".sretcarahc");
    CHECK(reverse("Lets all be unique together until we realise we are all "
                  "the "
                  "same.") == "Lets all be euqinu rehtegot litnu we "
                              "esilaer we "
                              "are all the .emas");
    CHECK(reverse("The old apple revels in its authority.") == "The old "
                                                               "elppa "
                                                               "slever in "
                                                               "its "
                                                               ".ytirohtu"
                                                               "a");
    CHECK(reverse("The shooter says goodbye to his love.") == "The retoohs "
                                                              "says "
                                                              "eybdoog to "
                                                              "his .evol");
    CHECK(reverse("Please wait outside of the house.") == "esaelP wait "
                                                          "edistuo "
                                                          "of the .esuoh");
    CHECK(reverse("Two seats were vacant.") == "Two staes were .tnacav");
}

TEST_CASE("week04::bridgeShuffle") {
    CHECK(bridgeShuffle({"A", "A", "A"}, {"B", "B", "B"})
          == std::vector<std::string>({"A", "B", "A", "B", "A", "B"}));
    CHECK(bridgeShuffle({"h", "h", "h"}, {"a", "a", "a"})
          == std::vector<std::string>({"h", "a", "h", "a", "h", "a"}));
    CHECK(bridgeShuffle({"C", "C", "C", "C"}, {"D"})
          == std::vector<std::string>({"C", "D", "C", "C", "C"}));
    CHECK(bridgeShuffle({"h", "h"}, {"u", "u", "u", "u", "u"})
          == std::vector<std::string>({"h", "u", "h", "u", "u", "u", "u"}));
}

TEST_CASE("week04::simonSays") {
    CHECK(simonSays({1, 2}, {5, 1}));
    CHECK(simonSays({1, 2, 3}, {0, 1, 2}));
    CHECK(simonSays({1, 2, 3, 4, 5}, {0, 1, 2, 3, 4}));
    CHECK_FALSE(simonSays({1, 2}, {5, 5}));
    CHECK_FALSE(simonSays({1, 2, 3, 4, 5}, {5, 5, 1, 2, 3}));
    CHECK_FALSE(simonSays({1, 2, 3, 4, 5}, {0, 1, 2, 3, 3}));
}

TEST_CASE("week04::lastDigit") {
    CHECK(lastDigit(1, 1, 1));
    CHECK(lastDigit(12, 15, 10));
    CHECK(lastDigit(15228, 9209, 72162));
    CHECK(lastDigit(-12, 15, -10));
    CHECK(lastDigit(15228, -9209, -72162));
    CHECK_FALSE(lastDigit(15, 1, 1));
    CHECK_FALSE(lastDigit(123, 15, 10));
    CHECK_FALSE(lastDigit(5213, 99219, 6165));
    CHECK_FALSE(lastDigit(1523, 513, 512));
    CHECK_FALSE(lastDigit(-15, 1, 1));
    CHECK_FALSE(lastDigit(123, -15, 10));
}

TEST_CASE("week04::checkPerfect") {
    CHECK(checkPerfect(6));
    CHECK(checkPerfect(28));
    CHECK(checkPerfect(496));
    CHECK(checkPerfect(8128));
    CHECK(checkPerfect(33550336));
    CHECK_FALSE(checkPerfect(12));
    CHECK_FALSE(checkPerfect(97));
    CHECK_FALSE(checkPerfect(481));
    CHECK_FALSE(checkPerfect(1001));
    CHECK_FALSE(checkPerfect(55555));
}

TEST_CASE("week04::isSubset") {
    CHECK(isSubset({1, 2}, {1, 2, 3}));
    CHECK(isSubset({1, 2, 3, 4}, {4, 3, 2, 1}));
    CHECK(isSubset({3, 2, 5}, {5, 3, 7, 9, 2}));
    CHECK(isSubset({8, 9}, {7, 1, 9, 8, 4, 5, 6}));
    CHECK_FALSE(isSubset({1, 2}, {3, 5, 9, 1}));
    CHECK_FALSE(isSubset({7, 9, 8, 4, 2}, {7, 9, 5, 8, 4}));
}

TEST_CASE("week04::isSmooth") {
    CHECK(isSmooth("Marta appreciated deep perpendicular right trapezoids"));
    CHECK(isSmooth("She eats super righteously"));
    CHECK(isSmooth("Ben naps so often"));
    CHECK(isSmooth("Mad dislikes sharp pointy yoyos"));
    CHECK(isSmooth("Rita asks Sam mean numbered dilemmas"));
    CHECK_FALSE(isSmooth("Someone is outside the doorway"));
    CHECK_FALSE(isSmooth("Cute triangles are cute"));
    CHECK_FALSE(isSmooth("Marigold daffodils streaming happily."));
    CHECK_FALSE(isSmooth("Simply wonderful laughing."));
}

TEST_CASE("week04::parseSubtitleLine") {
    using std::chrono::milliseconds;
    using namespace std::chrono_literals;

    using S = std::pair<milliseconds, std::string>;

    {
        auto opt = parseSubtitleLine("01:33:24.123 a subtitle");
        REQUIRE(opt.has_value());
        REQUIRE_EQ(*opt, S{5604123ms, "a subtitle"});
    }
    {
        auto opt = parseSubtitleLine("01:33:24.123 \t   a subtitle");
        REQUIRE(opt.has_value());
        REQUIRE_EQ(*opt, S{5604123ms, "a subtitle"});
    }
    {
        auto opt = parseSubtitleLine("01:33:24.123 a subtitle  ");
        REQUIRE(opt.has_value());
        REQUIRE_EQ(*opt, S{5604123ms, "a subtitle"});
    }
    {
        auto opt = parseSubtitleLine("01:33:24.123\ta subtitle\t");
        REQUIRE(opt.has_value());
        REQUIRE_EQ(*opt, S{5604123ms, "a subtitle"});
    }
    {
        auto opt = parseSubtitleLine("01:33:24.123 \ta subtitl\te\t");
        REQUIRE(opt.has_value());
        REQUIRE_EQ(*opt, S{5604123ms, "a subtitl\te"});
    }
    REQUIRE_FALSE(parseSubtitleLine(" 01:33:24.123 a subtitle").has_value());
    REQUIRE_FALSE(parseSubtitleLine("01:33:24.123a subtitle").has_value());
    REQUIRE_FALSE(parseSubtitleLine("01:33:24.3a subtitle").has_value());
    REQUIRE_FALSE(parseSubtitleLine("1:33:24.123a subtitle").has_value());
    REQUIRE_FALSE(parseSubtitleLine("01:1:24.123a subtitle").has_value());
    REQUIRE_FALSE(parseSubtitleLine("01:01:4.123a subtitle").has_value());
}

TEST_CASE("week04::marathon") {
    using namespace std::chrono_literals;

    CHECK(marathon(
              {
                  {1h, "Mary"},
                  {20min, "James"},
                  {50min, "Mike"},
                  {30min, "Jack"},
                  {30min, "Nathan"},
                  {35min, "Sarah"},
                  {55min, "Tom"},
                  {18min, "Chris"},
                  {40min, "John"},
              },
              30min, 50min)
          == std::vector<std::string>{"Jack", "Nathan", "Sarah", "John", "Mike"});
}

TEST_CASE("week04::lootItems") {
    const std::unordered_map<std::string, ItemMap> loots{
        {"Ogre", {{"gold", 10}, {"knife", 1}, {"potion", 3}}},
        {"Rizard", {{"silver", 2}, {"leather", 3}}},
        {"Wolf", {{"gold", 5}, {"leather", 4}, {"bone", 2}}},
        {"Slime", {{"gold", 1}, {"silver", 20}, {"potion", 1}}},
    };
    CHECK(lootItems({"Slime", "Rizard", "Slime", "Ogre", "Ogre", "Slime"}, loots)
          == ItemMap{{"gold", 23}, {"silver", 62}, {"knife", 2}, {"potion", 9}, {"leather", 3}});
}

TEST_CASE("week04::monteCarloIntegration") {
    using doctest::Approx;

    std::mt19937_64 rng{0};
    CHECK(monteCarloIntegration(
              // fn(x) = sqrt(x) (0에서 1까지의 제곱근 함수)
              0, 1, [](double x) { return std::sqrt(x); }, rng, 1000)
          == Approx(0.67433574918506012).epsilon(1e-10));

    rng.seed(0);
    CHECK(monteCarloIntegration(
              0, 1, [](double x) { return 3 * x * x; }, rng, 1000)
          == Approx(1.0114473596577886).epsilon(1e-10));
}