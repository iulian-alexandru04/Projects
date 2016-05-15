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
import javax.persistence.OneToMany;
import javax.persistence.OneToOne;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "DEPARTMENT")
public class Department implements Serializable {
	private static final long serialVersionUID = 349275834L;
	@Id
	@Column(name = "department_id")
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;

	@NotEmpty
	@Column(name = "department_name", nullable = false)
	private String departmentName;

	@NotEmpty
	@OneToOne(fetch = FetchType.LAZY)
	@JoinColumn(name = "boss_id", nullable = false)
	private Doctor doctor;

	@NotEmpty
	@OneToMany(fetch = FetchType.LAZY, mappedBy = "department")
	private Set<Doctor> doctors;

	public Department() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getDepartmentName() {
		return departmentName;
	}

	public void setDepartmentName(String departmentName) {
		this.departmentName = departmentName;
	}

	public Doctor getDoctor() {
		return doctor;
	}

	public void setDoctor(Doctor doctor) {
		this.doctor = doctor;
	}

	public Set<Doctor> getDoctors() {
		return doctors;
	}

	public void setDoctors(Set<Doctor> doctors) {
		this.doctors = doctors;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || !(o instanceof Department))
			return false;
		Department doc = (Department) o;
		if (id == null)
			return false;
		return id.equals(doc.getId());
	}

	@Override
	public int hashCode() {
		if (id != null)
			return 31 * id.hashCode();
		return 31 * super.hashCode();
	}
}
