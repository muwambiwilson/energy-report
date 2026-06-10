# ⚡ Industrial Energy Management System

A C-based utility designed for industrial facilities to monitor electrical efficiency and automate billing calculations. This system calculates Apparent Power and Power Factor, determines efficiency status, and generates a billing report in multiple currencies.

## 🚀 Features
* **Power Factor Analysis:** Calculates efficiency based on Real Power (P) and Reactive Power (Q).
* **Efficiency Monitoring:** Flags a "Low Power Factor" warning if the factor drops below 0.90.
* **Multi-Currency Billing:** Supports automated conversion from UGX to USD, GBP, and EUR.
* **Automated Reporting:** Generates a professional `energy_report.txt` file for record-keeping.

---

## 🛠️ Technical Logic
The system utilizes the standard power triangle relationship:

1. **Apparent Power (S):** S = sqrt(P^2 + Q^2)
2. **Power Factor (PF):** PF = P / S

---

## 💻 How to Run
### Prerequisites
* A C compiler (GCC, Clang, or MSVC).
* Standard Math library (`-lm` flag required on Linux/macOS).

### Compilation
```bash
gcc energy_system.c -o energy_system -lm
```
## YouTube Video Link
Here is the link to our project presentation video:
[For Energy reports]
(https://youtu.be/ChDPhaqDP8U?si=uaxoCEVCSY4eKivL)
