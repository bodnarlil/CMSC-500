#include "BitsOrganism.h"
using namespace std;
#include <random>

class BitsPop {

    std::vector<BitsOrganism> pop;
    int popsize;

public:

    BitsPop(int n, int genomesize) {
        popsize = n;
        for (int i = 0; i < n; i++) {
            BitsOrganism org = BitsOrganism(genomesize);
            pop.push_back(org);
        }
    }

    void update(std::vector<BitsOrganism> newpop) {
        std::copy(newpop.begin(), newpop.end(), pop);
    }

    std::vector<BitsOrganism> getPop() {
        return pop;
    }

    BitsOrganism getMax() {
        auto it = std::max_element(pop.begin(), pop.end());
        return *it;
    }

    std::vector<BitsOrganism> tournament_select(int tournsize) {
        // old numbers cooresponding to all the organisms in pop
        vector<int>organismNums;
        // int to hold max score of current subgroup of items in pop and location
        int maxScore = 0; int maxIndex = -1;
        // holds the new population
        vector<BitsOrganism> newPopulation;

        // give each pop a number (0 to popSize-1)
        // assign each population a unique number and store each num in an array and set each setFrac to their number
        for (int i = 0; i < pop.size(); i++) {
            pop[i].setFrac(i);
            organismNums.push_back(i);
        }
        // while organismNums is not empty: loop through organisms/tournsize to choose x number of random organisms and put them in a vector
        while (organismNums.size() != 0) {
            // run a tournament
            if (organismNums.size() < tournsize) { // too small for normal tournament, just use the current size
                for (int z = 0; z < organismNums.size(); z++) {
                    if (maxScore < pop[organismNums[z]].getScore()) {
                        maxScore = pop[organismNums[z]].getScore();
                        maxIndex = z;
                    }
                }
                newPopulation.push_back(pop[maxIndex]); // add final maxIndex to the new population
            }
            else { // organismNums.size() == tournsize | organismNums.size() > tournsize) {
                // find random selection of tournsize number of organisms
                vector<int>tournamentVector;

                // first set up the vector holding the organisms in the tournament
                for (int x = 0; x < tournsize; x++) {
                    int randInt = rand() % organismNums.size(); // random number between 0 and length of organismNums
                    tournamentVector.push_back(organismNums[randInt]); // send in the corresponding number at randInt
                    organismNums.erase(organismNums.begin() + randInt - 1); // delete that num from the whole organismNums list
                } // should have length tournsize

                // add max from there
                for (int z = 0; z < tournamentVector.size(); z++) {
                    if (maxScore < pop[tournamentVector[z]].getScore()) {
                        newPopulation.push_back(pop[maxIndex]);
                    }
                }
                newPopulation.push_back(pop[maxIndex]); // add the maxIndex to the new population
                maxIndex = 0; maxScore = -1; // reset stuff
            }
        }
    }

    // end of tournament select
    std::vector<BitsOrganism> roulette_select() {
        std::vector<BitsOrganism> newPopulation;

        // store all fitness in totalFitness
        int totalFitness = 0;
        for(int i = 0; i < pop.size(); i++){
            totalFitness += pop[i].getScore();
        }

        // get individual fitness as percent
        for (int i = 0; i < pop.size(); i++) {
            double fracScore = pop[i].getScore() / totalFitness;
            pop[i].setFrac(fracScore*100);
        }

        // holds 100 numbers corresponding to the percent per item in pop
        vector<int>allNums;
        int holderForj;
        // fill vec with numbers corresponding to pop
        for (int i = 0; i < pop.size(); i++) {
            // hold number j for the percent num matched to the pop at i
            vector<int>tempNums;
            for (int j = 0; j < pop[i].getFrac(); j++) {
                tempNums.push_back(j);
                holderForj = j;
            }
            // add temp vector to final vector
            allNums.insert(allNums.end(), tempNums.begin(), tempNums.end());
            // set number as j
            pop[i].setNum(holderForj);
        }

        // run popsize times to add new population based on fractions
        for (int i = 0; i < popsize; i++) {
            int randIndex = rand() % 100; // random number between 0 and 100
            int number = allNums[randIndex]; // random number that correlates to a pop
            for(int x = 0; x < pop.size(); x++){ // loop through all pop items
                if (number == pop[x].getNum()) { // if pop's num matches number, add it to newPop
                    newPopulation.push_back(pop[x]);
                }
            }
        }
        // return final pop
        return newPopulation;
    }

};