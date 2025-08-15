# P2P Application (Group Project)
## Introduction
The purpose of this project is to develop a P2P (Peer-to-Peer) network application, which is designed to facilitate content sharing among a number of peers through the support of an index server. The peers in this application can function as content servers (peers that provide content), content clients (peers that download content), or both. The communication between the index server and a peer is based on UDP, whereas the actual transfer of content is based on TCP. This project aims to demonstrate key P2P functionalities, namely content registration, downloading, listing, and deregistration, in order to showcase the seamless exchange of data within a distributed system.

In order to achieve this, a firm understanding of socket programming is needed. Socket programming enables communication over a network by providing an interface that allows applications to send and receive data through specific endpoints, which are known as sockets. In this project, the sockets, UDP and TCP, are used to achieve different objectives. UDP sockets enable fast, connectionless communication ideal for interacting with the index server, while TCP sockets facilitate secure and reliable data transfer between peers. Socket programming principles, such as establishing connections, transmitting data, and handling multiple sockets using tools like the ‘getsockname’ system call, ultimately form the technical foundation for creating this application.

## Description of Peer and Server Programs
Implementing the protocol requires handling various types of messages, namely content registration, downloading, listing, and deregistration. As mentioned previously, the UDP and TCP sockets are crucial for achieving different objectives for a successful P2P application. The protocol involves the use of PDUs (Protocol Data Units) which are categorized as R (registration), S (downloading), O (listing), and T (deregistration). With these in mind, the server must be able to maintain a content table and handle requests from peers and the peers must be able to send those requests to the server and process the responses.

### Peer
The peer program is responsible for sending various requests to the server and processing the responses accordingly. After typing in their name, the peer is then prompted to enter a command letter with a list of options given. Typing in a valid command letter results in that letter-type PDU being sent to the server to handle and perform the appropriate operation(s). 

Specifically, for content registration, an R-type PDU is sent to the server, where the data consists of the peer name, content name, and port number. Depending on the result, the peer should receive an A-type (acknowledgement) PDU from the server indicating a successful registration or an E-type (error) PDU otherwise.

If the peer wants to download content, an S-type PDU is sent to the server (with the data containing the content name), where it will then receive from the server either an S-type PDU if the search for the registered content was successful or an E-type PDU if the content was not found or registered.

The peer is also able to list out the registered contents by sending an O-type PDU to the server where, if successful, the peer should be able to process the response of the server and list out those specific contents. Otherwise, the peer receives an E-type PDU indicating that no content was registered.

The peer also has the ability to deregister contents by sending a T-type PDU to the server, where the peer must then receive either an A-type or E-type PDU from the server depending on if the deregistration was successful or not.

Finally, if the peer wants to quit the application, the contents must all be deregistered. By typing in ‘Q’ in the command prompt, the peer performs the same process for the deregistration command, except in this case, the person acting as the peer exits out of the loop of the application running and ends their entire session. 

### Server
The server program is responsible for receiving requests from peers given the command letter typed into the prompt and must be able to handle the content accordingly.

When the peer sends an R-type PDU, the server must first check if the content is registered. If it is not already registered, the content is registered with the associated address being stored and then it must send an A-type PDU back to the peer. However, if the content is already registered, regardless if it is by the same peer or not, an E-type PDU is sent back instead.

If the peer sends an S-type PDU, it must search for the content requested by the peer However, the content must first be registered by the peer. So, if the content is found, an S-type PDU is sent to the peer to confirm, while also containing the address of a content server. Otherwise, an E-type PDU is sent to the peer to indicate that the requested content is not found.

Once the peer sends an O-type PDU, the server must be able to display all the content that was registered by the peer as a list. If no content was ever registered by the peer, the server instead sends an E-type PDU back to the peer.

Regardless if the peer types in ‘T’ or ‘Q” in the command prompt, the server should receive a T-type PDU, where it is responsible for deregistering all of the peer’s content. But the difference is for ‘T’, an A-type or E-type PDU will be sent to indicate whether the registration was successful or not, whereas for Q, the server does not send back any PDU since the peer is going to be exiting out of the application.

##
This project was developed as part of COE768: Computer Networks at Toronto Metropolitan University.
