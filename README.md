# Hotel Management System

## Overview
The Hotel Management System is a C++ application designed to manage hotel operations, including room management and customer management. This project provides a user-friendly interface for hotel staff to efficiently handle various tasks related to hotel management.

## Features
- Add and remove rooms
- Check in and check out customers
- Manage room status (available, occupied, etc.)
- Store and retrieve customer information

## Project Structure
```
hotel-management-system
├── src
│   ├── main.cpp          # Entry point of the application
│   ├── hotel.cpp         # Implementation of the Hotel class
│   ├── hotel.h           # Definition of the Hotel class
│   ├── room.cpp          # Implementation of the Room class
│   ├── room.h            # Definition of the Room class
│   ├── customer.cpp       # Implementation of the Customer class
│   ├── customer.h         # Definition of the Customer class
│   └── utils
│       ├── utils.cpp     # Utility functions implementation
│       └── utils.h       # Utility functions declaration

├── include
│   └── utils.h           # External access to utility functions
├── tests
│   ├── test_hotel.cpp    # Unit tests for the Hotel class
│   ├── test_room.cpp     # Unit tests for the Room class
│   └── test_customer.cpp  # Unit tests for the Customer class
├── CMakeLists.txt        # Build configuration fileg
└── README.md             # Project documentation
```

## Setup Instructions
1. Clone the repository:
   ```
   git clone https://github.com/yourusername/hotel-management-system.git
   ```
2. Navigate to the project directory:
   ```
   cd hotel-management-system
   ```
3. Build the project using CMake:
   ```
   mkdir build
   cd build
   cmake ..
   make
   ```

## Usage
Run the application:
```
./hotel_management_system
```

Follow the on-screen instructions to manage hotel operations.

## Contributing
Contributions are welcome! Please open an issue or submit a pull request for any enhancements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for details.
