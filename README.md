# Chromosome-Simulation

This work simulates chromosome dynamics of plasmid, a synthesized chromosome outside cell environment.

The simulation is implemented by C++, and uses DataTank as its interphase. DataTank is a numerical work environment developed by David Adelsteinsson https://www.visualdatatools.com/DataTank/. It is powerful at processing and visualizing various formats of data, and it allows users to create custom C++ scripts externally using its default DTSource library.

The main program is "ChromoSimulator v13.tank". All input process, simulation process and output process are in this program using DataTank as interphase. It allows people to visualize output configuration real-time as simulation is progressing. The kernel C++ script is attached to the .tank file.

The following are the steps to run the simulation.

1. Download and install DataTank https://www.visualdatatools.com/DataTank/. Get the license by following instructions on the website. Get the simulation script "ChromoSimulator v13.tank".
2. Run "ChromoSimulator v13.tank" through DataTank. Set inputs before running the simulation.
3. To launch the simulation, typically two approaches are adopted. 
  a.	Local. This approach occupies machine CPU therefore potentially prevent users from multitasking, especially for long simulations, but it allows users to view the geometry simultaneously. 
  b.	Online. Submit the simulation and run it on a server with legal access to avoid local occupancy. This approach forbid simultaneous observation, however one can download the job and visualize at any time, even when the job is still running.
4. DataTank is only compatible with Xcode in MacOS as its C++ program compiler. It also provides built-in DTSource library as data structures and ports specifically for DataTank modules. 
  a.	Set the application to the attached script in “Parameter run” or “Task” module by clicking “Set” button and find the script under Tethered.tank file. 
  b. Compile or profile the C++ script in Xcode, and one shall find that in the scroll down list “Support”, either the “Debug version” or the “Release version” has been lit up. 
  c.	Select either the “Debug version” or the “Release version” as the project. 
  d.	If the simulation is run locally, click the “Run” button and the simulation starts to progress. 
  e.	If the simulation is to be submitted to server, by clicking “Create” button, DataTank creates a Parameter_run.dtask file which stores all required scripts and commands for submitting the job. Navigate to “Task—Run remotely—Add machine” and enter server information and access. Now click on “submit” button, and the job is successfully submitted to the server. The output data is also stored in the same Parameter_run.dtask file. While the file is open, DataTank periodically checks with the server about the progress and also downloads temporary results.
5. To get the simulation results, the approach depends on if the simulation is run locally or online. 
  a.	For local simulation, the output data is saved by DataTank into local cache. One can save the output in a custom .mat file as the simulation progresses. 
  b.	For online simulation, the output data is saved inside Parameter_run.dtask file.
The "dataAnalysisv2.tank" contains some stochastic analysis tools for the simulation.
