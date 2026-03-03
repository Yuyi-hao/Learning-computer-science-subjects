# Computer Networks

## Computer Network

A **computer network** is a collection of interconnected devices (called nodes) that communicate with each other through communication links in order to share resources and exchange information.

```
[Node A] ---- link ---- [Node B]
     \                    /
      \                  /
            [Node C]
```

### Purpose of a Computer Network
- Resource sharing (data, hardware, computing power)
- Communication between devices
- Distributed application support

#### Resources may include:
- Files and databases
- Printers and storage
- Processing capability
- Network services


## Nodes
A **node** is any device connected to a network that is capable of sending, receiving, or forwarding data.
```

+---------+
|  Node   |
| (Device)|
+---------+

If it can send/receive data → It is a node.

```
- Nodes are responsible for data transmission.  
- They do not physically propagate signals — that is handled by communication links.
- **Examples of Nodes** :- Computers , Servers , Printers , Security cameras , Routers , Switches , Bridges

---

## Communication Link
A **communication link** is the medium that carries data between nodes. It is responsible for transmitting or propagating signals from one device to another.

### Types of Communication Links
- **Wired**
  - Ethernet cables
  - Fiber optics
  ```
    [Computer] ===== Ethernet Cable ===== [Switch]
  ```
- **Wireless**
  - WiFi
  - Cellular signals
  - Radio waves
  ```
    [Phone] ))) ))) )))  [WiFi Router]
  ```

- Nodes generate and receive data.  
- Links carry the data.

---


## Types of Nodes

Nodes are broadly classified into two categories:

### End Devices (End Systems)

These are devices used directly by users or applications.
- Generate data, Consume data, Run applications
- **Examples** :- Smartphones, Laptops, Tablets, Printers, Web servers, Cameras etc.

```
  [Laptop]      [Phone]      [Printer]
      \            |             /
       \           |            /
                [Switch]
```


### Intermediate Devices

These devices assist in forwarding and managing data within the network.

- Forward packets, Connect multiple networks, Manage traffic
- **Examples** :- Routers, Switches, Modems, Wireless routers, Cellular towers
```
[PC] --\
         >-- [Switch] -- [Router] -- Internet
[Phone]-/
```
---


## The Internet

The **Internet** is a global network that connects billions of computing devices worldwide.
- The Internet is a **network of networks** rather than a single unified system.
- It enables communication between distributed systems across the globe.

These connected devices are known as:
- Hosts
- End systems

```
        Network A
      [PC]---[Router]
                 |
                 |
              [ISP]
                 |
        -----------------
        |               |
   Network B        Network C
  [Server]          [Laptop]

```

---

## Core Components of a Network

### Transmission Media

The **media** refers to the physical or wireless medium through which data propagates.
- **Examples** :- Copper cables , Fiber-optic cables , Radio waves

### Packets
Data is not transmitted as a single continuous block.

Instead:
1. The sending end system divides the data into smaller segments.
2. Header information is added to each segment.
3. Each formatted unit is called a **packet**.

Packets travel through communication links toward the destination.

**Message**
```
"This is a long message"
```

**segmented packets**
```
Packet 1: [Header | "This is"]
Packet 2: [Header | " a long"]
Packet 3: [Header | " message"]
```

**Traveling independently:**
```
[Packet1] --->  
[Packet2] --->   (may take different paths)
[Packet3] --->
```
---

### Router

A **router** is a network device that connects multiple networks and forwards packets toward their destination.
- Operates in the network core
- Connects packet switches
- Determines next hop for packets

```
             Network A
                |
                |
            +---------+
            | Router  |
            +---------+
             /       \
            /         \
     Network B     Network C
```


### Link-Layer Switch

A **link-layer switch** connects end devices within a local network.

- Operates in the access network
- Connects devices within the same local environment (e.g., office or building)
```
        +---------+
        | Switch  |
        +----+----+
             | 
     -------------------
     |        |        |
   [PC]    [Printer]  [Laptop]
```

---

## Internet Service Provider (ISP)
An **Internet Service Provider (ISP)** is an organization that provides end systems with access to the Internet.
- End systems connect to the Internet through an ISP.
- An ISP itself is a network composed of packet switches and communication links.
- ISPs interconnect to form the global Internet.
```
Your Home Network
------------------
[Phone]
   |
[Router]
   |
======== ISP =========
   |
[Global Internet]

```


---

## Protocols

A **protocol** is a set of rules that govern how data is transmitted and received between devices in a network.

Protocols define:
- Message format
- Message order
- Actions taken on transmission or reception
- Error handling procedures

All Internet components (end systems, routers, switches) operate using defined protocols.

```
Without protocol:

Device A: 101010???
Device B: WHAT??

With protocol:

Device A: [Header | Data]
Device B: Understood.

```

---

## Common Internet Protocols

### TCP (Transmission Control Protocol)

TCP provides reliable data transfer.
- Ensures correct delivery
- Maintains data order
- Detects and retransmits lost packets
- Controls flow and congestion
```
Sender -> Packet 1 ->
Sender -> Packet 2 ->
Sender -> Packet 3 ->

Receiver:
x Packet 1 received
x Packet 2 received
o Packet 3 missing

→ Request retransmission
```

### IP (Internet Protocol)

IP is responsible for addressing and routing packets.
- Defines packet format
- Assigns logical addresses
- Determines packet forwarding across networks
```
Packet:
+--------------------+
| Source IP          |
| Destination IP     |
| Data               |
+--------------------+
```

---

## Internet Standards
Internet standards are developed by the **IETF (Internet Engineering Task Force)**. The IETF publishes documents known as: **RFC (Request for Comments)**

- RFC documents define technical standards and protocols.
- These standards ensure interoperability across global systems.

**Examples of protocols documented in RFCs:**

- HTTP (Web communication)
- SMTP (Email transfer)
- TCP
- IP


---

## Applications and the Internet

The Internet provides services to applications running on end systems.

- **Examples of distributed applications** :- Online gaming, Real-time messaging, Video conferencing, Web browsing, Email systems
- Applications run on end devices, while the Internet provides the communication infrastructure.

---

## Packet Switching
Packet switching is a method of transferring data where packets are forwarded from one device to another across the network.

- Forward packets based on destination address
- Operate independently of the application layer

Their function is limited to moving packets toward the destination.

```
           Path 1
[Sender] -----------\
                     >--- [Receiver]
[Sender] -----------/
           Path 2
```
---


## Socket Interface
A **socket interface** provides the mechanism that allows applications on different end systems to communicate over the network.

- It Defines rules for sending and receiving data
- Acts as an interface between application and transport layer
- Enables process-to-process communication

```
+------------------+
|   Application    |
+--------+---------+
         |
         |  (Socket)
         v
+------------------+
| Transport Layer  |
+------------------+
```