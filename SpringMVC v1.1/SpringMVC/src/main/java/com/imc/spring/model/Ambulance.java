package com.imc.spring.model;

import java.io.Serializable;
import java.util.Date;
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
@Table(name = "AMBULANCE")
public class Ambulance implements Serializable {
	private static final long serialVersionUID = 3409284092L;

	@Id
	@Column(name = "ambulance_id", nullable = false)
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;

	@NotEmpty
	@Column(name = "ambulance_name", nullable = false, unique = true)
	private Integer number;

	@NotEmpty
	@Column(name = "capacity", nullable = false)
	private Integer capacity;

	@NotEmpty
	@Column(name = "last_service", nullable = false)
	private Date lastService;

	@NotEmpty
	@Column(name = "next_service", nullable = false)
	private Date nextService;

	@NotEmpty
	@OneToMany(fetch = FetchType.LAZY, mappedBy = "ambulance")
	private Set<Driver> drivers;

	public Ambulance() {
	}

	public Set<Driver> getDrivers() {
		return drivers;
	}

	public void setDrivers(Set<Driver> drivers) {
		this.drivers = drivers;
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public Integer getNumber() {
		return number;
	}

	public void setNumber(Integer number) {
		this.number = number;
	}

	public Integer getCapacity() {
		return capacity;
	}

	public void setCapacity(Integer capacity) {
		this.capacity = capacity;
	}

	public Date getLastService() {
		return lastService;
	}

	public void setLastService(Date lastService) {
		this.lastService = lastService;
	}

	public Date getNextService() {
		return nextService;
	}

	public void setNextService(Date nextService) {
		this.nextService = nextService;
	}

	@Override
	public boolean equals(Object o) {
		if (this == o)
			return true;
		if (o == null || !(o instanceof Ambulance))
			return false;
		Ambulance amb = (Ambulance) o;
		if (id == null)
			return false;
		return id.equals(amb.id);
	}

	@Override
	public int hashCode() {
		if (id == null)
			return 31 * super.hashCode();
		return 31 * id.hashCode();
	}
}
