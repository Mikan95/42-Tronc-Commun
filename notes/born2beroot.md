## BORN2BEROOT
1. [Difference between Debian and CentOS](https://github.com/Mikan95/42-Tronc-Commun/blob/main/notes/born2beroot.md#difference-between-debian-and-centos)
2. [Difference between apt and aptitude](https://github.com/Mikan95/42-Tronc-Commun/blob/main/notes/born2beroot.md#difference-between-apt-and-aptitude)
3. [AppArmor](https://github.com/Mikan95/42-Tronc-Commun/blob/main/notes/born2beroot.md#apparmor)
### Difference between _Debian_ and _CentOS_
**Debian** and **CentOS** are both popular Linux distributions, but they have some key differences:

1. **Package Management:**
	- **Debian** uses the APT (Advanced Package Tool) package management system, making it easy to install, update, and remove software.
	- **CentOS** uses the YUM (Yellowdog Updater, Modified) package management system, which simplifies the process of managing software packages.

2. **Release Cycle:**
	- **Debian** has a more flexible release cycle, with a stable version released when it is deemed ready. It tends to prioritize stability over having the latest software.
	- **CentOS** follows a more rigid release cycle and is known for its long-term support (LTS) releases. It is often used in enterprise environments for its stability.

3. **Community vs. Enterprise Focus:**
	- **Debian** is community-driven and is known for its inclusiveness and commitment to free software principles.
	- **CentOS** is derived from the sources of Red Hat Enterprise Linux (RHEL) and is geared more towards enterprise environments, with a focus on stability and support.

4. **Systemd:**
	- **Debian** adopted the systemd init system with Debian 8 (Jessie), which manages the initialization process and system services.
	- **CentOS** also switched to systemd with CentOS 7, aligning with the direction many Linux distributions took in adopting this init system.
5. **Default Software Versions:**
	- **Debian** often includes older but stable versions of software in its repositories to prioritize system stability.
	- **CentOS**, being more enterprise-focused, might include slightly older software versions compared to bleeding-edge distributions.

### Difference between _apt_ and _aptitude_
**apt** and **aptitude** are both package management tools usedin Debian-based Linux distributions like Debian itself and Ubuntu. While they serve similar purposes, there are some differences between the two:
1. **User Interface:**
	- **apt:** It has a simple and straightforward command-line interface. It's designed to be user-friendly and easy to use for basic package management tasks.
	- **aptitude:** It provides a more feature-rich and interactive command-line interface. It offers a text-based menu system that allows users to navigate and manage packages with a bit more flexibility.

2. **Dependency Handling:**
	- **apt:** Primarily focuses on installing, upgrading, and removing packages. It's adept at handling dependencies but may not provide as detailed information about conflicts or alternatives.
	- **aptitude:** Has a more advanced dependency resolution mechanism. It is often considered more powerful in handling complex dependency scenarios, and it can suggest solutions for package conflicts.

3. **Functionality:**
	- **apt:** Primarily focused on package management tasks and doesn't extend to other system management functions.
	- **aptitude:** Not only manages packages but also includes features like a text-based graphical user interface, search capabilities, and tracking of packages installed automatically as dependencies.

4. **Automatic Handling of Packages:**
	- **apt:** Does not automatically remove packages that are no longer needed (dependencies that were installed for a specific package but are no longer required).
	- **aptitude:** Can automatically remove orphaned packages, helping to keep the system clean from unnecessary dependencies.

5. **Recommended Packages:**
	- **apt:** Installs recommended packages by default, but it provides an option to skip them during installation.
	- **aptitude:** Does not automatically install recommended packages by default. Users need to explicitly request them.

In general, both apt and aptitude can be used for routine package management tasks, and the choice between them often comes down to personal preference. Some users prefer the simplicity of apt, while others appreciate the additional features and interactivity of aptitude.

### AppArmor
AppArmor is a Linux security module that limits what specific programs can do by creating rules for their actions. These rules, enforced by the kernel, restrict access to resources, reducing the impact of security threats or malicious software. Essentially, AppArmor enhances system security by controlling the behavior of individual applications on a Linux server.
+ **AppArmor:**
	- Controls the behavior of specific applications or processes by defining security profiles.
	- Specifies what resources an application is allowed to access, which files it can read or write, and what system calls it can make.
	- Protects against vulnerabilities or malicious activities within individual applications.

### Partitions and Logical Volume Management (LVM)
**A partition** is a logically divided section of a computer's hard drive or storage device. It is treated as an independent unit, and each partition can have its own file system and operating system. Partitions are used to organize and manage data on a storage device more efficiently.

**Logical Volume Management** (LVM) is a system that provides a higher-level, flexible way of managing disk space compared to traditional partitioning.

##### LVMs
1. **Physical Volumes (PV):**
	- Physical volumes are the actual storage devices or partitions (like hard drives or partitions on hard drives) that contribute to the LVM setup.

1. **Volume Groups (VG):**
	- Volume groups are created by combining one or more physical volumes. These can span multiple physical disks.
	- Volume groups act as a pool of storage from which logical volumes are created.

1. **Logical Volumes (LV):**
	- Logical volumes are created within volume groups and are analogous to partitions in traditional partitioning schemes.
	- Unlike partitions, logical volumes can easily be resized, moved, or even span multiple physical volumes.

1. **File Systems:**
	- File systems are then created on these logical volumes, allowing for the storage and retrieval of files.

In summary, LVM introduces a layer of abstraction between the physical storage devices (or partitions) and the file systems.  
This abstraction allows for **more flexibility in managing storage space**. You can dynamically resize logical volumes, add new physical volumes to a volume group, or create snapshots for backup purposes, all without disrupting the existing data.

**Traditional partitions have fixed sizes, and once you allocate space to them, changing their sizes or adding new partitions can be challenging.**  
LVM provides a dynamic and more versatile way to manage storage, making it easier to adapt to changing needs in terms of space allocation on a system.
