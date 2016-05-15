package com.imc.spring.dao;

import java.util.List;

import com.imc.spring.model.Ward;

public interface WardDao {
	Ward getWard(long Id);

	void updateWard(Ward ward);

	void addWard(Ward ward);

	void deleteWard(long Id);

	List<Ward> getWards();
}
