#pragma once

#include <boost/program_options.hpp>

#include "te/util/Singleton.h"

namespace te {
class TrueEngine;
class Log;

class Application : public Singleton<Application> {
public:
    /**
     * \brief Application specific constructor
     * \param argc App arguments count
     * \param argv App arguments values
     */
    Application(int argc, char** argv);

    /**
     * \brief Application destructor
     */
    ~Application();

    /**
     * \brief Run application
     * \return If all done then return 0, else return error code
     */
    int run();

    /**
     * \brief Get app arguments
     * \return App arguments
     */
    const boost::program_options::variables_map& getArgs() const;

    /**
     * \brief Get app arguments description
     * \return App arguments description
     */
    const boost::program_options::options_description& getArgsDescription() const;

private:
    /**
     * \brief Engine instance
     */
    std::unique_ptr<TrueEngine> m_engine;

    /**
     * \brief Log instance
     */
    std::unique_ptr<Log> m_log;

    /**
     * \brief Application parsed arguments
     */
    boost::program_options::variables_map m_appArgs;

    /**
     * \brief Application arguments description
     */
    boost::program_options::options_description m_appDescription;
};
} // namespace te