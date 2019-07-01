#include "SimpleEngine.h"

//#include <image_data_type.hpp>
//#include <pupil_detector.hpp>

#include <clara/stdlib/json_utils.hpp>

#include <cmath>
#include <iostream>

extern "C"
std::unique_ptr<clara::Engine> create_engine()
{
    return std::make_unique<SimpleEngine>();
}

clara::EngineData SimpleEngine::configure(clara::EngineData& input)
{
    // Clara provides a simple JSON parser to read configuration data
    // and configure the service.
    auto config = clara::stdlib::parse_json(input);

    // Example for when the service has state that is configured by
    // the orchestrator. The "state" object should be a std::shared_ptr
    // accessed atomically.
    //
    // (This service is actually stateless, so detector_ could just simply be
    // initialized in the service constructor).
    //std::atomic_store(&detector_, std::make_shared<PupilDetector>());
    return {};
}

clara::EngineData SimpleEngine::execute(clara::EngineData& input)
{
    auto output = clara::EngineData{};

    return output;
}


clara::EngineData SimpleEngine::execute_group(const std::vector<clara::EngineData>&)
{
    return {};
}


std::vector<clara::EngineDataType> SimpleEngine::input_data_types() const
{
    return { clara::type::JSON};//, IMAGE_TYPE };
}


std::vector<clara::EngineDataType> SimpleEngine::output_data_types() const
{
    return { clara::type::JSON};//, IMAGE_TYPE };
}


std::set<std::string> SimpleEngine::states() const
{
    return std::set<std::string>{};
}


std::string SimpleEngine::name() const
{
    return "SimpleEngine";
}


std::string SimpleEngine::author() const
{
    return "Joey Jo-Jo Junior Shabadoo";
}


std::string SimpleEngine::description() const
{
    return "Does nothing";
}


std::string SimpleEngine::version() const
{
    return "0.1";
}

