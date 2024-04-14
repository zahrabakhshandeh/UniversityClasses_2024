#include <iostream>

void moveDisk(char fromPeg, char toPeg, int disk) {
    std::cout << "Move disk " << disk << " from " << fromPeg << " to " << toPeg << std::endl;
}

void towerOfHanoi(int n, char sourcePeg, char destinationPeg, char auxiliaryPeg) {
    if (n == 1) {
        moveDisk(sourcePeg, destinationPeg, 1);
        return;
    }
    
    towerOfHanoi(n-1, sourcePeg, auxiliaryPeg, destinationPeg);
    
    moveDisk(sourcePeg, destinationPeg, n);
    
    towerOfHanoi(n-1, auxiliaryPeg, destinationPeg, sourcePeg);
}
/*
    towerOfHanoi(3, 'A', 'C', 'B')
    │
    ├── towerOfHanoi(2, 'A', 'B', 'C')
    │   │
    │   ├── towerOfHanoi(1, 'A', 'C', 'B')  -- Move Disk 1 from A to C
    │   │
    │   └── Move Disk 2 from A to B
    │   │
    │   └── towerOfHanoi(1, 'C', 'B', 'A')  -- Move Disk 1 from C to B
    │
    └── Move Disk 3 from A to C
    │
    └── towerOfHanoi(2, 'B', 'C', 'A')
        │
        ├── towerOfHanoi(1, 'B', 'A', 'C')  -- Move Disk 1 from B to A
        │
        └── Move Disk 2 from B to C
        │
        └── towerOfHanoi(1, 'A', 'C', 'B')  -- Move Disk 1 from A to C

*/
int main() {
    int n;
    std::cout << "Enter the number of disks: ";
    std::cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
