import matplotlib.pyplot as plt

# Data: VBE and IB values extracted from the provided input
VBE = [
    8.160838e-01, 7.972817e-01, 7.815008e-01, 7.615722e-01, 7.488232e-01, 
    7.324537e-01, 7.106447e-01, 6.831543e-01, 6.630809e-01, 6.514658e-01, 
    6.432276e-01
]
IB = [
    8.566216e-02, 6.800010e-02, 5.438700e-02, 3.908466e-02, 3.057747e-02, 
    2.131314e-02, 1.206465e-02, 5.126436e-03, 2.547287e-03, 1.667945e-03, 
    1.228721e-03
]

# Plot IB vs VBE
plt.figure(figsize=(8, 6))
plt.plot(VBE, IB, marker='o', color='b', linestyle='-', label='IB - VBE')
plt.xlabel('VBE (Base-Emitter Voltage)', fontsize=12)
plt.ylabel('IB (Base Current)', fontsize=12)
plt.title('IB vs VBE', fontsize=14)
plt.grid(True)
plt.legend()
plt.show()
