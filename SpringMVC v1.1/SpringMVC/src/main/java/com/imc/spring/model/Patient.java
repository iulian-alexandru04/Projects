package com.imc.spring.model;

import java.io.Serializable;
import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.JoinColumn;
import javax.persistence.JoinTable;
import javax.persistence.ManyToMany;
import javax.persistence.ManyToOne;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "PATIENT")
public class Patient implements Serializable {
	private static final long serialVersionUID = 1128342636L;
	@Id // pk
	@Column(name = "patient_id")
	@GeneratedValue(strategy = GenerationType.IDENTITY) // auto_increment
	private Long id;
	// if my database is empty and i use primitive types ill get a runtime error
	// so i use wraper types instead
	@NotEmpty
	@Column(name = "first_name", nullable = false)
	// not null column in my database +notempty (len>0)
	// if i decide to change a column in my db to be null ill only have to delte
	// @NotEmpty and nullable
	private String firstName;

	@NotEmpty
	@Column(name = "last_name", nullable = false)
	private String lastName;

	@NotEmpty
	@Column(name = "age", nullable = false)
	private Integer age;

	@NotEmpty
	@Column(name = "sex", nullable = false)
	private String sex;

	@NotEmpty
	@Column(name = "phone", nullable = false)
	private String phone;

	@NotEmpty
	@Column(name = "email", nullable = false)
	private String email;

	@NotEmpty
	@OneToOne(fetch = FetchType.LAZY)
	// load on demand, when needed
	@JoinColumn(name = "address", nullable = false)
	// referencedColumnName is optional since in the referenced table is only
	// one PK
	private Address address;

	@NotEmpty
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "doctor_id", nullable = false)
	private Doctor doctor;

	@NotEmpty
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "nurse_id", nullable = false)
	private Nurse nurse;

	@NotEmpty
	@ManyToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "room_id", nullable = false)
	private Room room;

	@NotEmpty
	@ManyToMany(fetch = FetchType.LAZY)
	@JoinTable(name = "PATIENT_BILL", joinColumns = { @JoinColumn(name = "patient_id") }, inverseJoinColumns = {
			@JoinColumn(name = "bill_id") })
	private Set<Bill> bills;

	@NotEmpty
	@ManyToMany(fetch = FetchType.LAZY)
	@JoinTable(name = "PATIENT_TEST", joinColumns = { @JoinColumn(name = "patient_id") }, inverseJoinColumns = {
			@JoinColumn(name = "test_id") })
	private Set<Test> tests;

	@NotEmpty
	@ManyToMany
	@JoinTable(name = "PATIENT_MEDICINE", joinColumns = { @JoinColumn(name = "patient_id") }, inverseJoinColumns = {
			@JoinColumn(name = "medicine_id") })
	private Set<Medicine> medicines;

	public Set<Bill> getBills() {
		return bills;
	}

	public void setBills(Set<Bill> bills) {
		this.bills = bills;
	}

	public Set<Test> getTests() {
		return tests;
	}

	public void setTests(Set<Test> tests) {
		this.tests = tests;
	}

	public Set<Medicine> getMedicines() {
		return medicines;
	}

	public void setMedicines(Set<Medicine> medicines) {
		this.medicines = medicines;
	}

	public Patient() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public Address getAddress() {
		return address;
	}

	public void setAddress(Address address) {
		this.address = address;
	}

	public Doctor getDoctor() {
		return doctor;
	}

	public void setDoctor(Doctor doctor) {
		this.doctor = doctor;
	}

	public Integer getAge() {
		return age;
	}

	public void setAge(Integer age) {
		this.age = age;
	}

	public String getSex() {
		return sex;
	}

	public void setSex(String sex) {
		this.sex = sex;
	}

	public Nurse getNurse() {
		return nurse;
	}

	public void setNurse(Nurse nurse) {
		this.nurse = nurse;
	}

	public Room getRoom() {
		return room;
	}

	public void setRoom(Room room) {
		this.room = room;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || !(o instanceof Patient))
			return false;
		Patient pat = (Patient) o;
		if (id == null)
			return false;
		return id.equals(pat.getId());
	}

	@Override
	public int hashCode() {
		if (id != null)
			return 31 * id.hashCode();
		return 31 * super.hashCode();
	}
}
