<br/>
<p align="center">
  <a href="https://github.com/The-Intruder/Dining-Philosophers-Simulator">
    <img src="https://cdn-icons-png.flaticon.com/512/5776/5776927.png" alt="Logo" width="80" height="80">
  </a>
  <h3 align="center">Dining Philosophers Simulator</h3>
  <p align="center">
    A simulation of the classic dining philosophers problem, which is a well-known synchronization problem in computer science.
    <br/>
    <br/>
    <a href="https://github.com/The-Intruder/Dining-Philosophers-Simulator/issues">Report Bug</a>
    .
    <a href="https://github.com/The-Intruder/Dining-Philosophers-Simulator/issues">Request Feature</a>
  </p>
  <div align="center">
    <a href="https://twitter.com/i_am_amine" target="_blank">
      <img  alt="Twitter Follow"  src="https://img.shields.io/twitter/follow/i_am_amine?style=social">
    </a>
    <img  src="https://img.shields.io/github/repo-size/The-Intruder/Dining-Philosophers-Simulator"  alt="Repo Size">
    <img  src="https://img.shields.io/github/last-commit/The-Intruder/Dining-Philosophers-Simulator"  alt="Last Commit">
    <img  src="https://img.shields.io/github/license/The-Intruder/Dining-Philosophers-Simulator" alt="License" >
    <img  src="https://img.shields.io/badge/Made%20with-❤-1f425f.svg"  alt="made-with-love">
  </div>
</p>


## Table Of Contents

- [Table Of Contents](#table-of-contents)
- [About The Project](#about-the-project)
- [Built With](#built-with)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [Usage](#usage)
- [Roadmap](#roadmap)
- [Contributing](#contributing)
  - [Creating A Pull Request](#creating-a-pull-request)
- [License](#license)
- [Authors](#authors)
- [Acknowledgements](#acknowledgements)

## About The Project

The Philosophers project is a fascinating exploration of concurrent programming and synchronization in the context of the dining philosophers problem. It challenges you to design and implement a solution that allows a fixed number of philosophers to peacefully share a dining table and a limited number of forks.

The project involves creating a simulation where each philosopher is represented as a separate thread, and the forks are shared resources. The philosophers alternate between thinking and eating, but to eat, they need to acquire two forks—one from their left and one from their right. However, certain conditions must be met to avoid conflicts, deadlocks, and starvation.

The Philosophers project provides an excellent opportunity to deepen your understanding of concurrent programming concepts, thread synchronization, and the challenges of resource sharing in a multithreaded environment. It requires careful consideration of various synchronization techniques and data structures to ensure the correct and efficient operation of the simulation.

## Built with

The Philosophers project is built using the following technologies and concepts:

- **C Programming Language:** The entire project is implemented in the C programming language, leveraging its low-level capabilities and system APIs for thread management, synchronization, and resource handling.

- **Multithreading:** The project utilizes multithreading to represent each philosopher as a separate thread, allowing them to perform concurrent actions, such as thinking and eating, in a simulated dining scenario.

- **Synchronization Techniques:** The project involves the use of synchronization techniques, such as mutexes or semaphores, to control access to shared resources (forks) and prevent conflicts and deadlocks.

- **Operating System Concepts:** The implementation of the Philosophers 42 project relies on various operating system concepts, including process management, thread synchronization, and resource allocation.

This project showcases the power of the C programming language and provides a practical exploration of multithreading and synchronization.

## Getting Started

To get started with the Philosophers project, follow the steps below:

### Prerequisites

- **C Compiler**: You need a C compiler installed on your system to compile and run the project. The most commonly used C compiler is GCC (GNU Compiler Collection), which is available for various platforms.

- **Operating System**: The project can be built and run on different operating systems, including Linux, macOS, and Windows. Ensure that your operating system supports the necessary tools and APIs for concurrent programming and thread management.

### Installation

1. **Clone the Repository**: Begin by cloning this repository to your local machine using the following command:

```bash
git clone https://github.dev/The-Intruder/Dining-Philosophers-Simulator philosophers
```

2. **Navigate to the Project Directory**: Change your current directory to the project directory:

```bash
cd philosophers
```

3. **Build the Project**: Use a C compiler to build the project. For example, if you're using GCC, you can use the following command:

```bash
make
```

By following these steps, you can easily get started with the Philosophers project and experience the intricacies of concurrent programming and resource management in a simulated dining scenario. Enjoy the journey of understanding and mastering synchronization in a multithreaded environment!

## Usage

1. **Run the Program**: Execute the compiled program to start the simulation:

```bash
./philosophers <number_of_philos> <time_to_sleep> <time_to_eat> <eating_count>
```

  - ***Note**: You can modify the project parameters, such as the number of philosophers and simulation duration, by editing the relevant variables in the source code before compiling, or just from the arguments.*

2. **Explore and Experiment**: Feel free to explore the code, experiment with different synchronization techniques, and make modifications to further enhance the project.

The program will run the dining philosophers simulation, showcasing the concurrent actions of the philosophers as they alternate between thinking and eating while avoiding conflicts and deadlocks.

## Roadmap

The Philosophers project aims to simulate the famous dining philosophers problem and provide a practical demonstration of concurrent programming and synchronization techniques. The following roadmap outlines the project's current status and potential future enhancements:

- **Step 1: Basic Implementation**: The initial phase focuses on implementing the core functionality of the dining philosophers simulation. This includes creating the necessary data structures, managing the philosophers' states, and implementing the required synchronization mechanisms to avoid conflicts and deadlocks.

- **Step 2: Parameterization**: The next step involves enhancing the project by making it more flexible and configurable. This may include allowing command-line arguments or configuration files to specify the number of philosophers, simulation duration, and other relevant parameters. By introducing parameterization, the project becomes more adaptable to different scenarios and requirements.

- **Step 3: Visualization and User Interface**: In this phase, the project can be enhanced by incorporating a graphical user interface (GUI) or visualization components. This allows users to observe the dining philosophers simulation in a more interactive and visually appealing manner. The GUI can display the philosophers' activities, their current states, and any relevant metrics or statistics.

- **Step 4: Performance Optimization**: As the project evolves, it's important to optimize its performance and resource utilization. This may involve identifying and resolving any potential bottlenecks, reducing unnecessary overhead, and improving the efficiency of the synchronization mechanisms. Performance optimization ensures that the simulation can handle larger numbers of philosophers or longer durations without significant slowdowns.

- **Step 5: Additional Features and Extensions**: Once the core functionality is in place, additional features and extensions can be considered to enhance the project further. This may include implementing advanced synchronization techniques, introducing different strategies for resource allocation, or incorporating more complex scenarios and interactions between the philosophers.

- **Step 6: Documentation and Refinement**: Throughout the development process, it's crucial to maintain proper documentation and refine the project's codebase. This includes writing clear and concise comments, providing detailed documentation on how to use the program and its various components, and ensuring that the code adheres to best practices and follows a consistent style.

This roadmap provides a general outline of the Philosophers project's development path. However, the actual roadmap may vary based on your specific goals, requirements, and available resources.

## Contributing

Contributions are what make the open source community such an amazing place to be learn, inspire, and create. Any contributions you make are **greatly appreciated**.

- If you have suggestions for adding or removing projects, feel free to [open an issue](https://github.com/The-Intruder/Dining-Philosophers-Simulator/issues/new) to discuss it, or directly create a pull request after you edit the _README.md_ file with necessary changes.
- Please make sure you check your spelling and grammar.
- Create individual PR for each suggestion.

### Creating A Pull Request

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## License

Distributed under the **GPL-3** License. See [LICENSE](https://github.com/The-Intruder/Dining-Philosophers-Simulator/blob/main/LICENSE.md) for more information.

## Authors

- **Mohamed Amine Naimi** aka ***[The-Intruder](https://github.com/The-Intruder/)*** - _Computer Science Student_ - *Built the Philosophers project*

## Acknowledgements

- [The-Intruder](https://github.com/The-Intruder/)

<!--
# Philosophers
In this project, we'll be practicing the basics of threading a process. We'll see how to create threads and we'll discover mutexes.

# Notes:
- Add a `-pthread` flag to the compilation command.
- `pthread_t` is the data type which holds the thread ID
- a _Thread_ is the smallest unit of processing that can be performed in an OS
- An Atomic action is one that effectively happens all at once, meaning that it is not splitted into several sub-actions, it either happens or doesn't , and it is 
- Each **Thread** has a its own _Stack_ and set of _Registers_

https://www.section.io/engineering-education/fork-in-c-programming-language/

- A thread shares the same Data Segment _(Uninitialized Data or BSS, and Initialized Data)_, Text Segment _(The actual code instructions of a program)_, and the Heap Segment, though they have independent call Stacks _(i.e. different Stack Segments)_, which are still reachable to each other through pointers _(though messing whith them can lead to undefined behaviour)_.

!!! note Accessing Variables outside our defined Scope
- You can access out-of-scope variables _(belonging to other functions)_ through pointers as long as they still exist, once their calling functions return, the behaviour becomes undefined
-->
