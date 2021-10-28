/**
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2021  Román Cárdenas Rodríguez
 * ARSLab - Carleton University
 * GreenLSI - Polytechnic University of Madrid
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _CADMIUM_CORE_SIMULATION_ABS_SIMULATOR_HPP_
#define _CADMIUM_CORE_SIMULATION_ABS_SIMULATOR_HPP_

#include <cadmium/core/modeling/component.hpp>
#include <limits>
#include <memory>

namespace cadmium {
    struct AbstractSimulator {
        double timeLast, timeNext;
        explicit AbstractSimulator(double time): timeLast(time), timeNext(std::numeric_limits<double>::infinity()) {};
        virtual ~AbstractSimulator() = default;

        virtual std::shared_ptr<Component> getComponent() = 0;
        virtual void collection(double time) = 0;
        virtual void transition(double time) = 0;
        virtual void clear() {
            getComponent()->clearPorts();
        };
    };
}

#endif //_CADMIUM_CORE_SIMULATION_ABS_SIMULATOR_HPP_
