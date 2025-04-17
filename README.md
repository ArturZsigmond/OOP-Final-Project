# Volunteering Manager App

A C++ application built with Qt for managing and assigning volunteers to departments and subjects based on suitability. This project supports a clean graphical user interface, efficient role matching, sorting capabilities, and modular design with clear separation between data models and UI logic.

## Features

- 📋 **Volunteer Assignment** – Match the best volunteers to suitable subjects based on department needs.
- 🧠 **Smart Sorting** – Sort volunteers by department, subject expertise, or availability.
- 🧩 **Modular Design** – Follows a clean architecture separating GUI, logic, and data layers.
- 👥 **Observer Pattern** – Updates UI components dynamically when data changes.
- 🖼️ **Qt GUI** – User-friendly and intuitive interface powered by Qt.

## Tech Stack

- **Language**: C++
- **GUI Framework**: Qt
- **Architecture**: Object-Oriented, Observer Design Pattern
- **Data**: `.txt` file-based persistence for departments and volunteers

## How to Build

1. Install **Qt** (version 5 or 6) and a C++ compiler (e.g., MSVC, MinGW, or Clang).
2. Open the project in **Qt Creator** or configure your build system (e.g., CMake or qmake).
3. Build the project using the IDE or command line.
4. Run the executable.

## Example Usage

- Add departments and subjects.
- Add volunteers and their competencies.
- Use the interface to match volunteers to relevant roles.
- Observe how changes reflect dynamically in different UI windows using the Observer pattern.

## Contributing

If you'd like to contribute:
- Fork the repository
- Create a new branch
- Submit a pull request

---

Happy volunteering! ❤️
