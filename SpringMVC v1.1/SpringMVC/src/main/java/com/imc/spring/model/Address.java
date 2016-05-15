package com.imc.spring.model;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;

import org.hibernate.validator.constraints.NotEmpty;

public class Address implements Serializable {
	private static final long serialVersionUID = 128342612336L;
	@Id
	@Column(name = "address_id", nullable = false)
	@GeneratedValue(strategy = GenerationType.IDENTITY)
	private Long id;

	@NotEmpty
	@Column(name = "street", nullable = false)
	private String street;

	@NotEmpty
	@Column(name = "postal_code", nullable = false)
	private Long postal_code;

	@Column(name = "house_number")
	private Integer houseNumber;

	@Column(name = "apartment_number")
	private Integer apartmentNumber;

	@NotEmpty
	@Column(name = "city", nullable = false)
	private String city;

	@NotEmpty
	@Column(name = "country", nullable = false)
	private String country;

	public Address() {
	}

	public Long getId() {
		return id;
	}

	public void setId(Long id) {
		this.id = id;
	}

	public String getStreet() {
		return street;
	}

	public void setStreet(String street) {
		this.street = street;
	}

	public Long getPostal_code() {
		return postal_code;
	}

	public void setPostal_code(Long postal_code) {
		this.postal_code = postal_code;
	}

	public Integer getHouseNumber() {
		return houseNumber;
	}

	public void setHouseNumber(Integer houseNumber) {
		this.houseNumber = houseNumber;
	}

	public Integer getApartmentNumber() {
		return apartmentNumber;
	}

	public void setApartmentNumber(Integer apartmentNumber) {
		this.apartmentNumber = apartmentNumber;
	}

	public String getCity() {
		return city;
	}

	public void setCity(String city) {
		this.city = city;
	}

	public String getCountry() {
		return country;
	}

	public void setCountry(String country) {
		this.country = country;
	}
}
