#include "catch.hpp"
#include "UtilityFunctions.hpp"
#include "stubs/FixedNumberGenerator.hpp"

SCENARIO("check createGenerator() function")
{
    GIVEN("Generator type FIBONACCI")
    {
        auto type = GeneratorType::FIBONACCI;

        WHEN("Generator is created with provided type")
        {
            auto generator = createGenerator(type);

            THEN("It should not be a null pointer")
            {
                CHECK(generator);
            }
        }
    }

    GIVEN("Not existing generator type")
    {
        auto type = static_cast<GeneratorType>(-1);

        WHEN("Generator is created with provided type")
        {
            THEN("It should throw logic_error")
            {
                CHECK_THROWS_AS(createGenerator(type), std::logic_error);
            }
        }
    }
}

SCENARIO("check sumGeneratedNumbers() function")
{
    GIVEN("FixedNumberGenerator stub and numberOfValues = 10")
    {
        auto generator = std::make_unique<FixedNumberGenerator>();
        auto numberOfValues = 10;

        WHEN("sumGeneratedNumbers is called")
        {
            auto result = sumGeneratedNumbers(std::move(generator), numberOfValues);

            THEN("It should return 420")
            {
                CHECK(result == numberOfValues * 42);
            }
        }
    }
}

SCENARIO("check sumNumbersFromGenerators() function")
{
    GIVEN("Empty generators collection and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 0")
            {
                CHECK(result == 0);
            }
        }
    }

    GIVEN("Generators collection with Fibonacci and PrimeNumber generator and numberOfValues = 1")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI, GeneratorType::PRIME};
        auto numberOfValues = 1;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 3")
            {
                CHECK(result == 3);
            }
        }
    }

    GIVEN("Generators collection with Fibonacci and PrimeNumber generator and numberOfValues = 3")
    {
        std::vector<GeneratorType> collection = {GeneratorType::FIBONACCI, GeneratorType::PRIME};
        auto numberOfValues = 3;

        WHEN("sumNumbersFromGenerators is called")
        {
            auto result = sumNumbersFromGenerators(collection, numberOfValues);

            THEN("It should return 14")
            {
                CHECK(result == 14);
            }
        }
    }
}