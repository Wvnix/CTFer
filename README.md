# CTFer

A tool to streamline preliminary reconnaissance for CTF challenges.

## Python Version

### Installation

**Note:** `nmap` must be installed on your system.

```sh
sudo pip install -r requirements.txt
```

### Usage

```sh
sudo python3 ctfer.py
```

### Notes:
- **Root privileges** (`sudo`) are required for advanced `nmap` features.
- **Warning:** Always review packages before using `pip` with elevated privileges.

### Input Guidelines:
- **URL:** Enter the domain directly with the scheme (e.g., `https://example.com`).
- **IP Address:** Use standard format (`X.X.X.X`).
- **Port Range:** Specify in the format `start-end` (e.g., `1-3333`). No default range.
- **Nmap Command:** Enter your preferred options **without quotes** (e.g., `-n -sS`).

---

## C Version

**Note:** `nmap` must be installed

### Compilation

```sh
gcc -o ctfer ctfer.c
```

### Usage

```sh
sudo ./ctfer
```

### Input Guidelines:
- **URL:** Enter without a scheme. 
- **IP Address:** Use standard format (`X.X.X.X`).
- **Port Range:** Specify in the format `start-end` (e.g., `1-3333`).
- **Nmap Command:** Enter options **without quotes** (e.g., `-n -sS`).



