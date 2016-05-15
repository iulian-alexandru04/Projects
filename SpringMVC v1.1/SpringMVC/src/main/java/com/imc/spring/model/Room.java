package com.imc.spring.model;

import java.io.Serializable;
import java.math.BigDecimal;
import java.util.Set;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.FetchType;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.OneToMany;
import javax.persistence.Table;

import org.hibernate.validator.constraints.NotEmpty;

@Entity
@Table(name = "ROOM")
public class Room implements Serializable {
	private static final long serialVersionUID = 1230912830L;

	@Id
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	@Column(name = "room_id", nullable = false)
	private Long id;

	@NotEmpty
	@Column(name = "room_number", nullable = false, unique = true)
	private Integer roomNumber;

	@NotEmpty
	@Column(name = "room_type", nullable = false)
	private String roomType;

	@NotEmpty
	@Column(name = "cost", nullable = false)
	private BigDecimal cost;

	@NotEmpty
	@OneToMany(fetch = FetchType.LAZY, mappedBy = "room")
	private Set<Patient> patients;

	public Room() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public Integer getRoomNumber() {
		return roomNumber;
	}

	public void setRoomNumber(Integer roomNumber) {
		this.roomNumber = roomNumber;
	}

	public String getRoomType() {
		return roomType;
	}

	public void setRoomType(String roomType) {
		this.roomType = roomType;
	}

	public BigDecimal getCost() {
		return cost;
	}

	public void setCost(BigDecimal cost) {
		this.cost = cost;
	}

	public Set<Patient> getPatients() {
		return patients;
	}

	public void setPatients(Set<Patient> patients) {
		this.patients = patients;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || !(o instanceof Room))
			return false;
		Room doc = (Room) o;
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
