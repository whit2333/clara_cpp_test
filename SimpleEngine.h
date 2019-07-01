#ifndef SIMPLE_SERVICE_HPP
#define SIMPLE_SERVICE_HPP

#include <clara/engine.hpp>

#include <atomic>
#include <memory>


class SimpleEngine : public clara::Engine
{
public:
  clara::EngineData configure(clara::EngineData& input) override ;

  clara::EngineData execute(clara::EngineData& input) override;

  clara::EngineData execute_group(const std::vector<clara::EngineData>& inputs) override;

public:
    std::vector<clara::EngineDataType> input_data_types() const override;

    std::vector<clara::EngineDataType> output_data_types() const override;

    std::set<std::string> states() const override;

public:
    std::string name() const override ;//{ return "derp";}

    std::string author() const override;//{ return "derp";}

    std::string description() const override;//{ return "derp";}

    std::string version() const override;//{ return "derp";}
};


#endif

