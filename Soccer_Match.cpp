/* To test and debug, the code was run multiple times. When changes were made to code logic, the code prior to the change was logged. 
        The different outputs were accounted for and assessed to identify any errors in the code. It was ensured that the output was logical
        and accurately corresponded with the event numbers and variables.

    example: 
        int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {}
            cout << "Team A has scored a goal!\n";
            }
    
    The output that was given now corresponds to the event number A. Therefore, the it follows logics of the code. 

*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std; 

int main() {

    int teamA_score = 0, teamB_score = 0;
    int AshotsOn_goal = 0, AshotsOff_goal = 0, BshotsOn_goal = 0, BshotsOff_goal = 0, Ablocked_shots = 0, Bblocked_shots = 0,fouls_A = 0, fouls_B = 0;
    int yellowA_cards = 0, yellowB_cards = 0, redA_cards = 0, redB_cards = 0;

    srand(time(0)); // Initialize random number generator

    int num_events = (rand() % 30 + 1); // Random number of events between 1 and 30
    cout << "Number of Events: " << num_events << "\n";

    int firstHalf_events = num_events / 2;
    int x = 1; // Generates event numbers

    // First Half
    while (x <= firstHalf_events) {
        int event_outcome = (rand() % 6 + 1); // Random event outcome
        cout << "\n Event " << x << ": \n";

        // Team A shoots
        if (event_outcome == 1) { 
            cout << "Team A has shot at the target.\n";
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team A has scored a goal!\n";
                teamA_score++;
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                AshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Ablocked_shots++;
            }
        } 
        
        // Team B shoots
        else if (event_outcome == 2) { 
            cout << "Team B has shot at the target.\n";
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team B has scored a goal!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                BshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Bblocked_shots++;
            }
        } 
        
        // Team B commits a foul
        else if (event_outcome == 3) { 
            cout << "Team B committed a foul. Team A was given a free kick!\n";
            fouls_B++;
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team A has scored a goal!\n";
                teamA_score++;
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                AshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Ablocked_shots++;
            }
            
            // Foul card result
            int foul_result = (rand() % 3); 
            if (foul_result == 0){
                cout << "No card was given. \n";
            }
            else if (foul_result == 1) {
                cout << "Yellow card was given to Team B.\n";
                yellowB_cards++;
            } else if (foul_result == 2) {
                cout << "Red card was given to Team B.\n";
                redB_cards++;
            }
        } 
        
        // Team A commits a foul
        else if (event_outcome == 4) { 
            cout << "Team A committed a foul. Team B was given a free kick!\n";
            fouls_A++;
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team B has scored a goal!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                BshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Bblocked_shots++;
            }
            
                // Foul card result
                int foul_result = (rand() % 3); 
                if (foul_result == 0) {
                    cout << "No card was given. \n";
                } else if (foul_result == 1) {
                    cout << "Yellow card was given to Team A.\n";
                    yellowA_cards++;
                } else if (foul_result == 2) {
                    cout << "Red card was given to Team A.\n";
                    redA_cards++;
                }
        } 
        
        // Team B commits a foul close to goal
        else if (event_outcome == 5) {  
            cout << "Team B committed a foul close to the goal. Team A was awarded a penalty!\n";
            fouls_B++;
            int shot_outcome = (rand() % 3);
            if (shot_outcome == 0) {
                cout << "Team A has scored with the penalty!\n";
                teamA_score++; 
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Penalty was saved by the goalkeeper!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else {
                cout << "Penalty was missed!\n";
                AshotsOff_goal++;
            }
            
                int foul_result = (rand() % 3);
                if (foul_result == 0) {
                    cout << "No card was given. \n";
                } else if (foul_result == 1) {
                    cout << "Yellow card was given to Team B. \n";
                    yellowB_cards++;
                } else if (foul_result == 2) {
                    cout << "Red card was given to Team B. \n";
                    redB_cards++;
                }
        }
        
        // Team A commits a foul close to goal
        else if (event_outcome == 6) { 
            cout << "Team A committed a foul close to the goal. Team B was awarded a penalty!\n";
            fouls_A++;
            int shot_outcome = (rand() % 3);
            if (shot_outcome == 0) {
                cout << "Team B has scored with the penalty!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Penalty was saved by the goalkeeper!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else {
                cout << "Penalty was missed!\n";
                BshotsOff_goal++;
            }

                int foul_result = (rand() % 3);
                if (foul_result == 0) {
                    cout << "No card was given. \n";
                } else if (foul_result == 1) {
                    cout << "Yellow card was given to Team A. \n";
                    yellowA_cards++;
                } else if (foul_result == 2) {
                    cout << "Red card was given to Team A. \n";
                    redA_cards++;
                }
        }

        x++;
    }

    // First half stats
    cout << "\n       Half Time Stats:        \n";
    cout << "-------------------------------------- \n";
    cout << "           Team A Stats           \n";
    cout << "Goals: " << teamA_score << " \n"; 
    cout << "Shots on Goal: " << AshotsOn_goal << " | " << " Shots Off Goal: " << AshotsOff_goal << " \n"; 
    cout << "Blocked Shots: " << Ablocked_shots << " | " << " Fouls: " << fouls_A;
    cout << "Yellow Cards: " << yellowA_cards << " | " << " Red Cards: " << redA_cards << "\n";
    cout << "______________________________________ \n";
    cout << "           Team B Stats           \n";
    cout << "Goals: " << teamB_score << " \n"; 
    cout << "Shots on Goal: " << BshotsOn_goal << " | " << " Shots Off Goal: " << BshotsOff_goal << " \n"; 
    cout << "Blocked Shots: " << Bblocked_shots << " | " << " Fouls: " << fouls_B << " \n";
    cout << "Yellow Cards: " << yellowB_cards << " | " << " Red Cards: " << redB_cards << "\n";
 
    srand(time(0)); 
    while (x <= num_events) {
        
        int event_outcome = (rand() % 6 + 1);
        cout << "\n Event " << x << ": \n";

       // Team A shoots
        if (event_outcome == 1) { 
            cout << "Team A has shot at the target.\n";
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team A has scored a goal!\n";
                teamA_score++;
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                AshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Ablocked_shots++;
            }
        } 
        
        // Team B shoots
        else if (event_outcome == 2) { 
            cout << "Team B has shot at the target.\n";
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team B has scored a goal!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                BshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Bblocked_shots++;
            }
        } 
        
        // Team B commits a foul
        else if (event_outcome == 3) { 
            cout << "Team B committed a foul. Team A was given a free kick!\n";
            fouls_B++;
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team A has scored a goal!\n";
                teamA_score++;
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                AshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Ablocked_shots++;
            }
            
            // Foul card result
            int foul_result = (rand() % 3); 
            if (foul_result == 0){
                cout << "No card was given. \n";
            }
            else if (foul_result == 1) {
                cout << "Yellow card was given to Team B.\n";
                yellowB_cards++;
            } else if (foul_result == 2) {
                cout << "Red card was given to Team B.\n";
                redB_cards++;
            }
        } 
        
        // Team A commits a foul
        else if (event_outcome == 4) { 
            cout << "Team A committed a foul. Team B was given a free kick!\n";
            fouls_A++;
            int shot_outcome = (rand() % 4);
            if (shot_outcome == 0) {
                cout << "Team B has scored a goal!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Saved by goalkeeper or last defender!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else if (shot_outcome == 2) {
                cout << "Shot was made off the goal!\n";
                BshotsOff_goal++;
            } else if (shot_outcome == 3) {
                cout << "Shot was blocked by a non-defender player!\n";
                Bblocked_shots++;
            }
            
            // Foul card result
            int foul_result = (rand() % 3); 
            if (foul_result == 0) {
                cout << "No card was given. \n";
            } else if (foul_result == 1) {
                cout << "Yellow card was given to Team A.\n";
                yellowA_cards++;
            } else if (foul_result == 2) {
                cout << "Red card was given to Team A.\n";
                redA_cards++;
            }
        } 
        
        // Team B commits a foul close to goal
        else if (event_outcome == 5) {  
            cout << "Team B committed a foul close to the goal. Team A was awarded a penalty!\n";
            fouls_B++;
            int shot_outcome = (rand() % 3);
            if (shot_outcome == 0) {
                cout << "Team A has scored with the penalty!\n";
                teamA_score++; 
                AshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Penalty was saved by the goalkeeper!\n";
                AshotsOn_goal++;
                Ablocked_shots++;
            } else {
                cout << "Penalty was missed!\n";
                AshotsOff_goal++;
            }
            
                int foul_result = (rand() % 3);
                if (foul_result == 0) {
                    cout << "No card was given. \n";
                } else if (foul_result == 1) {
                    cout << "Yellow card was given to Team B. \n";
                    yellowB_cards++;
                } else if (foul_result == 2) {
                    cout << "Red Card was given to Team B.\n";
                    redB_cards++;
             }
        } 
        
        // Team A commits a foul close to goal
        else if (event_outcome == 6) { 
            cout << "Team A committed a foul close to the goal. Team B was awarded a penalty!\n";
            fouls_A++;
            int shot_outcome = (rand() % 3);
            if (shot_outcome == 0) {
                cout << "Team B has scored with the penalty!\n";
                teamB_score++;
                BshotsOn_goal++;
            } else if (shot_outcome == 1) {
                cout << "Penalty was saved by the goalkeeper!\n";
                BshotsOn_goal++;
                Bblocked_shots++;
            } else {
                cout << "Penalty was missed!\n";
                BshotsOff_goal++;
            }

                int foul_result = (rand() % 3);
                if (foul_result == 0) {
                    cout << "No card was given. \n";
                } else if (foul_result == 1) {
                    cout << "Yellow card was given to Team A. \n";
                    yellowA_cards++;
                } else if (foul_result == 2) {
                    cout << "Red card was given to Team A. \n";
                    redA_cards++;
                }
        }
    
        x++;
    }       

    // Final stats
    cout << "\n       Final Stats:        \n";
    cout << "-------------------------------------- \n";
    cout << "           Team A Stats           \n";
    cout << "Goals: " << teamA_score << " \n"; 
    cout << "Shots on Goal: " << AshotsOn_goal << " | " << "Shots Off Goal: " << AshotsOff_goal << " \n"; 
    cout << "Blocked Shots: " << Ablocked_shots << " | " << "Fouls: " << fouls_A;
    cout << "Yellow Cards: " << yellowA_cards << " | " << "Red Cards: " << redA_cards << "\n";
    cout << "______________________________________ \n";
    cout << "           Team B Stats           \n";
    cout << "Goals: " << teamB_score << " \n"; 
    cout << "Shots on Goal: " << BshotsOn_goal << " | " << "Shots Off Goal: " << BshotsOff_goal << " \n"; 
    cout << "Blocked Shots: " << Bblocked_shots << " | " << "Fouls: " << fouls_B << " \n";
    cout << "Yellow Cards: " << yellowB_cards << " | " << "Red Cards: " << redB_cards << "\n";
    
    // Declaring the winner
    if (teamA_score > teamB_score)
        cout << "\n Team A is OUR WINNER TODAYYYY!";
    else if (teamA_score == teamB_score)
        cout << "\n We have a tie!! GREAT JOB EVERYONE!";
    else if (teamA_score < teamB_score)
        cout << "\n Team B is OUR WINNER TODAYYYY!";

    cout << "\n \n Thats all folks! Good Game!!!";

    return 0;
} 